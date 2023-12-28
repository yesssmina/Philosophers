/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 01:12:28 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/28 02:37:36 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_dead_flag(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_of_philosophers)
	{
		pthread_mutex_lock(philo->meal_mutex);
		if (current_time() - philo[i].last_meal_time
			>= philo->data->time_to_die)
		{
			print_action(philo->data, "died", philo[i].id);
			pthread_mutex_lock(&philo->data->dead_mutex);
			philo->data->dead_flag_data = 1;
			pthread_mutex_unlock(&philo->data->dead_mutex);
			pthread_mutex_unlock(philo->meal_mutex);
			return (1);
		}
		pthread_mutex_unlock(philo->meal_mutex);
		i++;
		usleep(1);
	}
	return (0);
}

int	ft_check_eat(t_philo *philo)
{
	int	i;
	int	end_of_meal;

	i = 0;
	end_of_meal = 0;
	if (philo->data->have_to_eat == -1)
		return (0);
	while (i < philo->data->nb_of_philosophers)
	{
		pthread_mutex_lock(philo[i].meal_mutex);
		if (philo[i].nb_meals_eaten >= philo->data->have_to_eat)
			end_of_meal++;
		pthread_mutex_unlock(philo[i].meal_mutex);
		i++;
	}
	if (end_of_meal == philo->data->nb_of_philosophers)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->dead_flag_data = 1;
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	return (0);
}

void	*ft_check(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ft_dead_flag(philo) == 1 || ft_check_eat(philo) == 1)
		{
			break ;
		}
	}
	return (arg);
}

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->dead_flag_data == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (0);
}

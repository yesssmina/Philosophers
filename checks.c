/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:23:12 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/29 14:00:05 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Checks if any philosopher has died due to not eating within the time_to_die.

int	ft_dead_flag(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->nb_of_philosophers)
	{
		pthread_mutex_lock(philo[i].meal_mutex);
		if (current_time() - philo[i].last_meal_time >= philo->data->time_to_die
			&& philo[i].eat_flag_philo == 0)
		{
			print_action(philo->data, "died", philo[i].id);
			pthread_mutex_lock(&philo->data->dead_mutex);
			philo->data->dead_flag_data = 1;
			pthread_mutex_unlock(&philo->data->dead_mutex);
			pthread_mutex_unlock(philo[i].meal_mutex);
			return (1);
		}
		pthread_mutex_unlock(philo[i].meal_mutex);
		i++;
	}
	return (0);
}

// Checks if all philosophers have eaten the specified number of times.

int	ft_check_eat(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->data->have_to_eat == -1)
		return (0);
	while (i < philo->data->nb_of_philosophers)
	{
		pthread_mutex_lock(&philo->data->meal_mutex);
		if (philo[i].nb_meals_eaten < philo->data->have_to_eat)
		{
			pthread_mutex_unlock(&philo->data->meal_mutex);
			return (0);
		}
		i++;
	}
	pthread_mutex_lock(&philo->data->dead_mutex);
	philo->data->dead_flag_data = 1;
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (1);
}

// Continuously checks for death or completion of eating requirements of philo.

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

// Checks the dead flag.

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

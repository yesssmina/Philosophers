/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:12:21 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/13 23:02:44 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = current_time();
	while ((current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

void	ft_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_t *lower_fork = (philo->id % 2 == 0) ? philo->right_fork : philo->left_fork;
    pthread_mutex_t *higher_fork = (philo->id % 2 == 0) ? philo->left_fork : philo->right_fork;

    pthread_mutex_lock(lower_fork);
    print_action(data, "has taken a fork", philo->id, current_time());

	if (data->nb_of_philosophers == 1)
	{
		ft_usleep(data->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	
    pthread_mutex_lock(higher_fork);
    print_action(data, "has taken a fork", philo->id, current_time());
    print_action(data, "is eating", philo->id, current_time());

    pthread_mutex_lock(&philo->meal_mutex);
    philo->nb_meals_eaten++;
    philo->last_meal_time = current_time();
    pthread_mutex_unlock(&philo->meal_mutex);

    ft_usleep(data->time_to_eat);

    pthread_mutex_unlock(higher_fork);
    pthread_mutex_unlock(lower_fork);
}

void	ft_think(t_philo *philo)
{
	print_action(philo->data, "is thinking", philo->id, current_time());
}

void	ft_sleep(t_philo *philo)
{
	print_action(philo->data, "is sleeping", philo->id, current_time());
	ft_usleep(philo->data->time_to_sleep);
}



void	*philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	t_data	*data = philo->data;

    while (1) // Une boucle qui représente le cycle de vie du philosophe
	{
		ft_eat(data, philo);
		ft_sleep(philo);
		ft_think(philo);

		pthread_mutex_lock(&philo->meal_mutex);
		if ((current_time() - philo->last_meal_time >= data->time_to_die) ||
			(data->have_to_eat != -1 && philo->nb_meals_eaten >= data->have_to_eat))
		{
			print_action(philo->data, "is dead", philo->id, current_time());
			pthread_mutex_unlock(&philo->meal_mutex);
			break;
		}
		pthread_mutex_unlock(&philo->meal_mutex);
	}
	return (arg);
}

// probleme avec la mort, revoir la boucle while 1 et verif toutes les mort possible 
// et retirer dead si la boucle se termine selon le dernier argument
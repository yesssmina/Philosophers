/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:12:21 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/13 02:01:17 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo)
{
	// Prendre les fourchettes (mutexes)
        pthread_mutex_lock(philo->right_fork);
		printf("%lu %d has taken a fork\n", current_time(), philo->id);
		if (philo->nb_of_philosophers == 1)
		{
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
        pthread_mutex_lock(philo->left_fork);
		printf("%lu %d has taken a fork\n", current_time(), philo->id);
		printf("%lu %d is eating\n", current_time(), philo->id);

        // Manger
        // Mettre à jour le temps du dernier repas et incrémenter nb_meals_eaten
		
		philo->nb_meals_eaten++;
		philo->last_meal_time = current_time();
		usleep(data->time_to_eat * 1000);
		
        // Poser les fourchettes
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);
}

void	ft_think(t_philo *philo)
{
	printf("%lu %d is thinking\n", current_time(), philo->id);
}

void	ft_sleep(t_philo *philo)
{
	printf("%lu %d is sleeping\n", current_time(), philo->id);
}

void *philo_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

    while (1) // Une boucle qui représente le cycle de vie du philosophe
	{
		ft_eat(philo);
		ft_think(philo);
		ft_sleep(philo);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 01:30:59 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/29 15:15:06 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Manages the fork-taking process for philosophers.

void	ft_has_token_a_fork(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(data, "has taken a fork", philo->id);
		pthread_mutex_lock(philo->left_fork);
		print_action(data, "has taken a fork", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(data, "has taken a fork", philo->id);
		pthread_mutex_lock(philo->right_fork);
		print_action(data, "has taken a fork", philo->id);
	}
	print_action(data, "is eating", philo->id);
}

// Philo wait for a certain period before trying to eat again.

void	wait_end_of_service(t_data *data, t_philo *philo)
{
	if (data->nb_of_philosophers % 2 == 1 && philo->i != 0)
	{
		while (((current_time() - philo->start) - (philo->last_meal_time
					- philo->start)) < (data->time_to_eat * 2 + 10))
			usleep(10);
	}
	if (data->nb_of_philosophers % 2 == 0 && philo->i != 0)
	{
		while ((current_time() - philo->start) - (philo->last_meal_time
				- philo->start) < (data->time_to_eat + 1))
			usleep(1);
	}
}

// Manages the eating process for philosophers.

void	ft_eat(t_data *data, t_philo *philo)
{
	if (data->nb_of_philosophers == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(data, "has taken a fork", philo->id);
		ft_usleep(data->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	wait_end_of_service(data, philo);
	ft_has_token_a_fork(data, philo);
	pthread_mutex_lock(philo->meal_mutex);
	philo->last_meal_time = current_time();
	philo->nb_meals_eaten++;
	pthread_mutex_unlock(philo->meal_mutex);
	ft_usleep(data->time_to_eat);
	if (philo->id % 2 == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

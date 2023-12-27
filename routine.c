/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:12:21 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/27 15:01:20 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
}

void	ft_eat(t_data *data, t_philo *philo)
{
	if (data->nb_of_philosophers == 1)
	{
		print_action(data, "has taken a fork", philo->id);
		ft_usleep(data->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	if (data->nb_of_philosophers % 2 == 1 && philo->i != 0)
	{
		while (((current_time() - philo->start) - (philo->last_meal_time
					- philo->start)) < (data->time_to_eat * 2 + 10));
		usleep(1);
	}
	ft_has_token_a_fork(data, philo);
	if (dead_check(philo))
		return ;
	print_action(data, "is eating", philo->id);
	pthread_mutex_lock(philo->meal_mutex);
	philo->last_meal_time = current_time();
	philo->nb_meals_eaten++;
	pthread_mutex_unlock(philo->meal_mutex);
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void	ft_think(t_philo *philo)
{
	print_action(philo->data, "is thinking", philo->id);
}

void	ft_sleep(t_philo *philo)
{
	print_action(philo->data, "is sleeping", philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->nb_of_philosophers % 2 == 0 && philo->id % 2 == 0)
	{
		ft_usleep(data->time_to_eat);
	}
	while (!dead_check(philo))
	{
		ft_eat(data, philo);
		ft_sleep(philo);
		ft_think(philo);
		philo->i++;
	}
	return (arg);
}

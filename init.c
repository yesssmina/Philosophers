/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:59:14 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/27 12:14:07 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_args(t_data *data, t_philo *philo, char **av)
{
	data->nb_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->have_to_eat = ft_atoi(av[5]);
	else
		data->have_to_eat = -1;
}

void	ft_init_mutex(t_data *data, t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	data->philo = philo;
	if (pthread_mutex_init(&data->mutex_lock, NULL) != 0
		|| pthread_mutex_init(&data->dead_mutex, NULL) != 0
		|| pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		printf("Error\nmutex init failed\n");
		return ;
	}
	while (i < data->nb_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error\nmutex init failed\n");
			return ;
		}
		i++;
	}
	pthread_mutex_lock(&data->dead_mutex);
	data->dead_flag_data = 0;
	pthread_mutex_unlock(&data->dead_mutex);
}

void	ft_init_philos(t_data *data, t_philo *philo,
	pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philosophers)
	{
		philo[i].i = 0;
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].eat_flag_philo = 0;
		philo[i].nb_meals_eaten = 0;
		philo[i].start = current_time();
		philo[i].time_since_last_meal = current_time();
		philo[i].last_meal_time = current_time();
		philo[i].meal_mutex = &data->mutex_lock;
		philo[i].right_fork = &forks[i];
		if (i == 0)
			philo[i].left_fork = &forks[data->nb_of_philosophers - 1];
		else
			philo[i].left_fork = &forks[i - 1];
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:59:14 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/12 18:01:42 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_args(t_data *data, char **av)
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

void	ft_init_mutex(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philosophers)
	{
		if(pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error\nmutexes init failed\n");
			return (1);
		}
		i++;
	}
}

void	ft_init_philos(t_data *data, pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;

	while (i < data->nb_of_philosophers)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_meals_eaten = 0;
		data->philo[i].left_fork = &forks[i];
		data->philo[i].right_fork = &forks[(i + 1) % data->nb_of_philosophers];
		i++;
	}
}

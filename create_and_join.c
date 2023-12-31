/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:25:18 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/28 13:32:49 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Creates threads for each philosopher and a monitoring thread.

void	ft_create_thread(t_data *data, pthread_mutex_t *forks,
	t_philo *philosophers)
{
	int	i;

	i = 0;
	if (pthread_create(&data->check, NULL, &ft_check, data->philo) != 0)
	{
		ft_destroy_mutex(data, forks);
		printf("Error\nThread creation\n");
		return ;
	}
	while (i < data->nb_of_philosophers)
	{
		if (pthread_create(&philosophers[i].philo_thread, NULL,
				&philo_routine, &philosophers[i]) != 0)
		{
			ft_destroy_mutex(data, forks);
			printf("Error\nThread creation\n");
			return ;
		}
		i++;
	}
}

// Waits for all philosopher threads and the monitoring thread to finish.

void	ft_join_thread(t_data *data, t_philo *philosophers,
	pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (pthread_join(data->check, NULL) != 0)
		ft_destroy_mutex(data, forks);
	while (i < data->nb_of_philosophers)
	{
		if (pthread_join(philosophers[i].philo_thread, NULL) != 0)
			ft_destroy_mutex(data, forks);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:25:18 by sannagar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/28 01:12:06 by sannagar         ###   ########.fr       */
=======
/*   Updated: 2023/12/27 12:23:56 by sannagar         ###   ########.fr       */
>>>>>>> 4a61101077f61d28a8ec75d61409c3520b9ff57e
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

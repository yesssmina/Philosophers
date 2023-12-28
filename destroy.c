/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:19:04 by sannagar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/28 01:19:36 by sannagar         ###   ########.fr       */
=======
/*   Updated: 2023/12/27 12:14:39 by sannagar         ###   ########.fr       */
>>>>>>> 4a61101077f61d28a8ec75d61409c3520b9ff57e
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_destroy_mutex(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->mutex_lock);
	pthread_mutex_destroy(&data->dead_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	while (i < data->nb_of_philosophers)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

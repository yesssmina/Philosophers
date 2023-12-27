/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:19:04 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/25 14:14:34 by sannagar         ###   ########.fr       */
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
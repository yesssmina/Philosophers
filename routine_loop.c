/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:12:21 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/28 02:19:43 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->nb_of_philosophers % 2 == 0 && philo->id % 2 == 0)
		ft_usleep(data->time_to_eat);
	while (!dead_check(philo))
	{
		ft_eat(data, philo);
		ft_sleep(philo);
		ft_think(philo);
		philo->i++;
	}
	return (arg);
}

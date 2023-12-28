/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 01:42:16 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/28 02:20:31 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *philo)
{
	print_action(philo->data, "is thinking", philo->id);
}

void	ft_sleep(t_philo *philo)
{
	print_action(philo->data, "is sleeping", philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

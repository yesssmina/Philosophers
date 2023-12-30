/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:28:58 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/30 00:45:48 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Prints the action of a philosopher if the simulation is still running.

void	print_action(t_data *data, const char *mess, int id)
{
	long	time;
	int		is_dead;

	pthread_mutex_lock(&data->dead_mutex);
	is_dead = data->dead_flag_data;
	pthread_mutex_unlock(&data->dead_mutex);
	if (!is_dead)
	{
		pthread_mutex_lock(&data->print_mutex);
		time = current_time() - data->philo->start;
		printf("%ld %d %s\n", time, id, mess);
		pthread_mutex_unlock(&data->print_mutex);
	}
}

// Converts a string to an integer.

int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	if (i != 1 && str[i] == '-' )
	{
		sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb = sign * nb;
	return (nb);
}

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

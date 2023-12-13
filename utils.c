/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:28:58 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/13 22:17:52 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, const char *mess, int id, long long time)
{
	pthread_mutex_lock(&data->mutex_lock);
	time = current_time() - data->philo->start;
	printf("*%lld* [%d] %s\n", time, id, mess);
	pthread_mutex_unlock(&data->mutex_lock);
}

long long current_time(void)
{
	struct timeval time;
	if (gettimeofday(&time, NULL) == -1)
		printf("gettimeofday() error\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000); // Convertir en millisecondes
}

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




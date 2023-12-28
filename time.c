/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:17:00 by sannagar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/28 01:25:04 by sannagar         ###   ########.fr       */
=======
/*   Updated: 2023/12/27 14:09:40 by sannagar         ###   ########.fr       */
>>>>>>> 4a61101077f61d28a8ec75d61409c3520b9ff57e
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t mil)
{
	size_t	end;
	size_t	current;

	current = current_time();
	end = current + mil;
	while (current < end)
	{
		current = current_time();
		if (end - current > 5)
			usleep(5000);
		else
			usleep(1000);
		current = current_time();
	}
	return (0);
}

long long	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error\ngettimeofday\n");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

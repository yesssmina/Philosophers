/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:17:00 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/21 13:31:18 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_usleep(size_t mil)
{
    size_t start;
    size_t end;
    size_t current;

    start = current_time();
    end = start + mil;
    while ((current = current_time()) < end)
    {
        if (end - current > 5)
            usleep(5000); // Dormir 5ms si le temps restant est supérieur à 5ms
        else
            usleep(1000); // Sinon, dormir 1ms pour plus de précision
    }
    return (0);
}

long long current_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error\ngettimeofday\n");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000)); // Convertir en millisecondes
}

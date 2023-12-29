/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:21:30 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/29 14:06:11 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo			philosophers[MAX_PHILOSOPHERS];
	pthread_mutex_t	forks[MAX_PHILOSOPHERS];
	t_data			data;

	if (ac != 5 && ac != 6)
	{
		printf("Error\nargument count invalid\n");
		return (1);
	}
	if (check_args(av) == 1 || check_max_allowed_arg(av) == 1)
		return (1);
	ft_init_args(&data, av);
	ft_init_mutex(&data, philosophers, forks);
	ft_init_philos(&data, philosophers, forks);
	ft_create_thread(&data, forks, philosophers);
	ft_join_thread(&data, philosophers, forks);
	ft_destroy_mutex(&data, forks);
	return (0);
}

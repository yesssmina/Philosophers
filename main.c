/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:21:30 by sannagar          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/28 01:18:41 by sannagar         ###   ########.fr       */
=======
/*   Updated: 2023/12/27 12:16:31 by sannagar         ###   ########.fr       */
>>>>>>> 4a61101077f61d28a8ec75d61409c3520b9ff57e
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
	ft_init_args(&data, philosophers, av);
	if (data.nb_of_philosophers > MAX_PHILOSOPHERS)
	{
		printf("Error\ntoo many philosophers\n");
		return (1);
	}
	ft_init_mutex(&data, philosophers, forks);
	ft_init_philos(&data, philosophers, forks, av);
	ft_create_thread(&data, forks, philosophers);
	ft_join_thread(&data, philosophers, forks);
	ft_destroy_mutex(&data, forks);
}

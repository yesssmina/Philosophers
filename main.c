/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:21:30 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/26 02:52:22 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int ac, char **av)
{
	t_philo			philosophers[MAX_PHILOSOPHERS];
	pthread_mutex_t forks[MAX_PHILOSOPHERS];
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
	//puts("ici16");
	ft_destroy_mutex(&data, forks);
	//puts("ici17");
}

//presque ok, verifier les tests, probleme de mort des fois, 
//check mauvais arg

	//if (data->nb_of_philosophers % 2 == 1)
	//{
	//	if (philo->id % 2 == 1 && philo->id != data->nb_of_philosophers)
	//	{
	//		ft_usleep(data->time_to_eat);
	//	}
	//	else if (philo->id % 2 == 0)
	//	{
	//		ft_usleep(data->time_to_eat * 2);
	//	}
	//}
	//else
	//{
	//	if (philo->id % 2 == 0)
	//	{
	//		ft_usleep(data->time_to_eat);
	//	}
	//}
	
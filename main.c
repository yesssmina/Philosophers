/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:21:30 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/13 17:15:32 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	ft_create_thread(t_data *data, pthread_mutex_t *forks, pthread_t *philosophers)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philosophers)
	{
		pthread_create(&philosophers[i], NULL, philo_routine, (void *)&(data->philo[i]));
		i++;
	}
}

void	ft_join_thread(t_data *data, pthread_t *philosophers)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philosophers)
	{
		pthread_join(philosophers[i], NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	pthread_t		philosophers[MAX_PHILOSOPHERS];
	pthread_mutex_t forks[MAX_PHILOSOPHERS];
	t_data			data;

	if (ac != 5 && ac != 6)
	{
		printf("Error\nargument count invalid\n");
		return (1);
	}
	ft_init_args(&data, av);

	if (data.nb_of_philosophers > MAX_PHILOSOPHERS)
	{
		printf("Error\ntoo many philosophers\n");
		return (1);
	}

	ft_init_mutex(&data, forks);
	ft_init_philos(&data, forks, av);
	ft_create_thread(&data, forks, philosophers);
	ft_join_thread(&data, philosophers);

	ft_destroy_mutex(&data, forks);
}
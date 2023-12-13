/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:21:30 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/13 02:18:07 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	ft_create_thread(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->nb_of_philosophers)
	{
		pthread_create(&philosophers[i], NULL, philo_routine, (void *)&(data->philo[i]))
		i++;
	}

}
// lock_mutex deja ajoute a la structure, a ajouter autour des printf, mais comment?
int	main(int ac, char **av)
{
	pthread_t		philosophers[MAX_PHILOSOPHERS];
	pthread_mutex_t forks[MAX_PHILOSOPHERS];
	t_data			data;

	ft_init_args(&data, av);
	if (ac != 5 && ac != 6)
	{
		printf("Error\nargument count invalid\n");
		return (1);
	}

	if (data.nb_of_philosophers > MAX_PHILOSOPHERS)
	{
		printf("Error\ntoo many philosophers\n");
		return (1);
	}

	ft_init_mutex(&data, forks);
	ft_init_philos(&data, forks, av);
	ft_create_thread(&data, forks);



	ft_destroy_mutex(&data, forks);
}
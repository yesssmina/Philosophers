/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:25:18 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/27 03:43:23 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// va trop vite, verif ft_dead_flag
int	ft_dead_flag(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->data->nb_of_philosophers)
	{
		pthread_mutex_lock(philo[i].meal_mutex);
		if (current_time() - philo[i].last_meal_time >= philo->data->time_to_die
			&& philo[i].eat_flag_philo == 0)
		{
			print_action(philo->data, "died", philo[i].id);

			pthread_mutex_lock(&philo->data->dead_mutex);
			philo->data->dead_flag_data = 1;
			pthread_mutex_unlock(&philo->data->dead_mutex);
			pthread_mutex_unlock(philo[i].meal_mutex);
			return (1);
		}
		pthread_mutex_unlock(philo[i].meal_mutex);
		i++;
		//usleep(1);
	}
	return (0);
}

// check cte fonction change
int	ft_check_eat(t_philo *philo)
{
	int	i;
	int	end_of_meal;

	i = 0;
	end_of_meal = 0;
	//puts("ici9");
	if (philo->data->have_to_eat == -1)
		return (0);
	while (i < philo->data->nb_of_philosophers)
	{
		//printf("i:%d\nnb_philo:%d\nhave_to_eat%d\n", i, philo->data->nb_of_philosophers, philo->data->have_to_eat);
		pthread_mutex_lock(philo[i].meal_mutex);
		if (philo[i].nb_meals_eaten >= philo->data->have_to_eat)
			end_of_meal++;
		pthread_mutex_unlock(philo[i].meal_mutex);
		i++;
	}
	if (end_of_meal == philo->data->nb_of_philosophers)
	{
		pthread_mutex_lock(&philo->data->dead_mutex);
		philo->data->dead_flag_data = 1;
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	return (0);
}

void	*ft_check(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	//puts("ici4");
	while (1)
	{
		//puts("ici5");
		if (ft_dead_flag(philo) == 1 || ft_check_eat(philo) == 1)
		{
		//	puts("ici6");
			break ;
		}
	}
	//puts("ici7");
	return (arg);
}

void	ft_create_thread(t_data *data, pthread_mutex_t *forks, t_philo *philosophers)
{
	//pthread_t	check;
	int	i;

	i = 0;
	//puts("ici");
	if (pthread_create(&data->check, NULL, &ft_check, data->philo) != 0)
	{
		//puts("ici1");
		ft_destroy_mutex(data, forks);
		printf("Error\nThread creation\n");
		return ;
	}
	while (i < data->nb_of_philosophers)
	{
		//puts("ici2");
		if (pthread_create(&philosophers[i].philo_thread, NULL,
			&philo_routine, &philosophers[i]) != 0)
		{
			ft_destroy_mutex(data, forks);
			printf("Error\nThread creation\n");
			return ;
		}
		i++;
		//puts("ici3");
	}
}

void	ft_join_thread(t_data *data, t_philo *philosophers, pthread_mutex_t *forks)
{
	//pthread_t	check;
	int	i;

	i = 0;
	//puts("ici13");
	if (pthread_join(data->check, NULL) != 0)
		ft_destroy_mutex(data, forks);
	while (i < data->nb_of_philosophers)
	{
		//puts("ici14");
		if (pthread_join(philosophers[i].philo_thread, NULL) != 0)
			ft_destroy_mutex(data, forks);
		i++;
	}
}

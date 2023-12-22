/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:12:21 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/22 12:07:20 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_t *lower_fork;
    pthread_mutex_t *higher_fork;

	lower_fork = (philo->id % 2 == 0) ? philo->right_fork : philo->left_fork;
	higher_fork = (philo->id % 2 == 0) ? philo->left_fork : philo->right_fork;
    pthread_mutex_lock(lower_fork);
    print_action(data, "has taken a fork", philo->id);

	if (data->nb_of_philosophers == 1)
	{
		ft_usleep(data->time_to_die);
		pthread_mutex_unlock(lower_fork);
		return ;
	}
	
    pthread_mutex_lock(higher_fork);
    print_action(data, "has taken a fork", philo->id);
	philo->eat_flag_philo = 1;
    print_action(data, "is eating", philo->id);

    pthread_mutex_lock(philo->meal_mutex);
    philo->last_meal_time = current_time();
    philo->nb_meals_eaten++;
    pthread_mutex_unlock(philo->meal_mutex);

    ft_usleep(data->time_to_eat);
	philo->eat_flag_philo = 0;
    pthread_mutex_unlock(higher_fork);
    pthread_mutex_unlock(lower_fork);
}

void	ft_think(t_philo *philo)
{
	print_action(philo->data, "is thinking", philo->id);
}

void	ft_sleep(t_philo *philo)
{
	print_action(philo->data, "is sleeping", philo->id);
	ft_usleep(philo->data->time_to_sleep);
}

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (*philo->dead_flag_philo == 1)
	{
		pthread_mutex_unlock(philo->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_mutex);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;

 	//if (philo->id % 2 == 0) {
    //    ft_usleep(1);
    //}
	//puts("la?");
	//printf("hte:%d\n", philo->have_to_eat);
    while (!dead_check(philo)) // Une boucle qui représente le cycle de vie du philosophe
	{
		ft_eat(data, philo);
		ft_sleep(philo);
		ft_think(philo);
		//puts("loop?");
	}
	return (arg);
}

// probleme avec la mort, revoir la boucle while 1 et verif toutes les mort possible 
// et retirer dead si la boucle se termine selon le dernier argument
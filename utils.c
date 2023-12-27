/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:28:58 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/27 03:01:22 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_data *data, const char *mess, int id)
{
	long long	time;
	int			is_dead;

	pthread_mutex_lock(&data->dead_mutex);
	is_dead = data->dead_flag_data;
	pthread_mutex_unlock(&data->dead_mutex);
	if (!is_dead)
	{
		pthread_mutex_lock(&data->print_mutex);
		time = current_time() - data->philo->start;
		printf("%lld %d %s\n", time, id, mess);
		pthread_mutex_unlock(&data->print_mutex);
	}
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



/*


void	ft_eat(t_data *data, t_philo *philo)
{
	if (data->nb_of_philosophers == 1)
	{
		print_action(data, "has taken a fork", philo->id);
		ft_usleep(data->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}

	if (data->i != 0)
	{
		printf("id:%d, current_time:%lld, last_meal_time:%lld\n", philo->id, current_time() - data->philo->start, philo->last_meal_time - data->philo->start);
		while (((current_time() - data->philo->start) - (philo->last_meal_time - data->philo->start)) < (data->time_to_eat * 2))
		{
			usleep(1);
		}
		//usleep(10);
		//if (data->nb_of_philosophers % 2 == 1 && philo->id == data->nb_of_philosophers)
		//{
		//	ft_usleep(1);
		//}
	}

    if (philo->id == data->nb_of_philosophers)
	{
        pthread_mutex_lock(philo->right_fork);
        print_action(data, "has taken a fork", philo->id);
        pthread_mutex_lock(philo->left_fork);
        print_action(data, "has taken a fork", philo->id);
		print_action(data, "is eating", philo->id);
    }
	else
	{
        pthread_mutex_lock(philo->left_fork);
        print_action(data, "has taken a fork", philo->id);
        pthread_mutex_lock(philo->right_fork);
        print_action(data, "has taken a fork", philo->id);
		print_action(data, "is eating", philo->id);
		//ft_usleep(data->time_to_eat);
    }
	pthread_mutex_lock(philo->meal_mutex);
	philo->last_meal_time = current_time();
	philo->nb_meals_eaten++;
	pthread_mutex_unlock(philo->meal_mutex);

	ft_usleep(data->time_to_eat);
	
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);


	
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
	pthread_mutex_lock(&philo->data->dead_mutex);
	if (philo->data->dead_flag_data == 1)
	{
		pthread_mutex_unlock(&philo->data->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->dead_mutex);
	return (0);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
 	if (data->nb_of_philosophers % 2 == 1)
	{
		if (philo->id == data->nb_of_philosophers)
		{
			ft_usleep(data->time_to_eat * 2);
		}
		else if (philo->id % 2 == 0)
		{
			ft_usleep(data->time_to_eat);
		}
	}
	else
	{
		if (philo->id % 2 == 0)
		{
			ft_usleep(data->time_to_eat);
			//usleep(10);
		}
	}
    while (!dead_check(philo)) // Une boucle qui représente le cycle de vie du philosophe
	{
		ft_eat(data, philo);
		ft_sleep(philo);
		ft_think(philo);
		//puts("loop?");
		data->i++;
	}
	return (arg);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:22:44 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/12 17:24:33 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>

# define MAX_PHILOSOPHERS 500

typedef struct s_philo
{
	int				id;
	int				nb_meals_eaten;

	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	
}				t_philo;


typedef struct s_data
{
	int				nb_of_philosophers;

	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				nb_meals_eaten;
	int				have_to_eat;
	t_philo			philo[MAX_PHILOSOPHERS];
	
}				t_data;

int		ft_atoi(const char	*str);

void	ft_init_mutex(t_data *data, pthread_mutex_t *forks);
void	ft_init_philos(t_data *data, pthread_mutex_t *forks, char **av);
void	ft_create_thread(t_data *data, pthread_mutex_t *forks);
void	ft_destroy_mutex(t_data *data, pthread_mutex_t *forks);


#endif

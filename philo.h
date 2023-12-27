/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:22:44 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/27 03:12:26 by sannagar         ###   ########.fr       */
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
# include <sys/time.h>

# define MAX_PHILOSOPHERS 200

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				nb_meals_eaten;
	long long		last_meal_time;
	long long		start;
	int				eat_flag_philo;
	pthread_t		philo_thread;
	pthread_mutex_t *meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;

	int				i;
	int 			time_since_last_meal;
}				t_philo;


typedef struct s_data
{
	int				nb_of_philosophers;
	int				dead_flag_data;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				have_to_eat;
	pthread_mutex_t	mutex_lock;
	pthread_mutex_t dead_mutex;
	pthread_mutex_t print_mutex;
	t_philo			*philo;
	pthread_t		check;
}				t_data;

int			ft_atoi(const char	*str);
void		ft_init_args(t_data *data, t_philo *philo, char **av);
void		ft_init_mutex(t_data *data, t_philo *philo, pthread_mutex_t *forks);
void		ft_init_philos(t_data *data, t_philo *philo, pthread_mutex_t *forks, char **av);
void		ft_create_thread(t_data *data, pthread_mutex_t *forks, t_philo *philosophers);
void		ft_join_thread(t_data *data, t_philo *philosophers, pthread_mutex_t *forks);
void		ft_destroy_mutex(t_data *data, pthread_mutex_t *forks);
long long	current_time(void);
void		print_action(t_data *data, const char *mess, int id);
void		ft_eat(t_data *data, t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		*philo_routine(void *arg);
int			ft_usleep(size_t mil);

int	ft_dead_flag(t_philo *philo);
int	ft_check_eat(t_philo *philo);
void	*ft_check(void *arg);
int	dead_check(t_philo *philo);


#endif

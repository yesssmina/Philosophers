/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 03:27:45 by sannagar          #+#    #+#             */
/*   Updated: 2023/12/28 04:39:43 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_digit_args(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **av)
{
	if (ft_atoi(av[1]) > MAX_PHILOSOPHERS || ft_atoi(av[1]) <= 0
		|| check_digit_args(av[1]) == 1)
	{
		printf("Error\ntoo many philosophers or wrong arg\n");
		return (1);
	}
	if (ft_atoi(av[2]) <= 0 || check_digit_args(av[2]) == 1
		|| ft_atoi(av[3]) <= 0 || check_digit_args(av[3]) == 1)
	{
		printf("Error\nwrong time_to_die or time_to_eat\n");
		return (1);
	}
	if (ft_atoi(av[4]) <= 0 || check_digit_args(av[4]) == 1)
	{
		printf("Error\nwrong time_to_sleep\n");
		return (1);
	}
	if (av[5] && (ft_atoi(av[5]) < 0 || check_digit_args(av[5]) == 1))
	{
		printf("Error\nwrong number of times each philosopher must eat\n");
		return (1);
	}
	return (0);
}

int	check_max_allowed_arg(char **av)
{
	if (ft_atoi(av[2]) > MAX_TIME_ARG)
	{
		printf("Error\nthe time_to_die time is too high... it's useless!\n");
		printf("try with less\n");
		return (1);
	}
	else if (ft_atoi(av[3]) > MAX_TIME_ARG)
	{
		printf("Error\nthe time_to_eat time is too high... it's useless!\n");
		printf("try with less\n");
		return (1);
	}
	else if (ft_atoi(av[4]) > MAX_TIME_ARG)
	{
		printf("Error\nthe time_to_sleep time is too high... it's useless!\n");
		printf("try with less\n");
		return (1);
	}
	else if (av[5] && ft_atoi(av[5]) > MAX_TIME_ARG)
	{
		printf("Error\nnumber of times each philo must eat is too high...\n");
		printf("it's useless! try with less\n");
		return (1);
	}
	return (0);
}

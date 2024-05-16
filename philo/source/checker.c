/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:28:51 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/16 23:36:46 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Error: wrong number of arguments\n", 34);
		return (false);
	}
	if (!all_digit(argc, argv))
	{
		write(2, "Error: arguments must be numbers\n", 34);
		return (false);
	}
	if (!non_negative(argc, argv))
	{
		write(2, "Error: arguments must be positive and not zero\n", 48);
		return (false);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		write(2, "Error: too many philosophers, sorry\n", 37);
		return (false);
	}
	return (true);
}

bool	all_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	non_negative(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (false);
		i++;
	}
	return (true);
}

bool	everyone_alive(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data->dying);
	while (i < philo->data->num_of_philo)
	{
		if (philo->data->philo[i].state == DIED)
			return (true);
		i++;
	}
	pthread_mutex_unlock(&philo->data->dying);
	return (false);
}

bool	everyone_ate(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->data->eating);
	while (i < philo->data->num_of_philo)
	{
		if (philo->data->philo[i].meal_count < philo->data->must_eat)
			return (false);
		i++;
	}
	pthread_mutex_unlock(&philo->data->eating);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:32:29 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/17 23:33:45 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	philo_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(t_philo *philo, int time)
{
	int	begin;

	begin = philo_time();
	(void)philo;
	while (philo_time() - begin < time)
	{
		usleep(150);
	}
}

int	time_shift(t_philo *philo)
{
	int	result;

	if (philo->data->num_of_philo % 2 != 0)
	{
		if (philo->data->time_to_eat >= philo->data->time_to_sleep)
		{
			result = philo->data->time_to_eat - philo->data->time_to_sleep;
			ft_usleep(philo, result);
			usleep(500);
		}
		else if (philo->data->time_to_sleep > philo->data->time_to_eat)
		{
			result = philo->data->time_to_sleep - philo->data->time_to_eat;
			ft_usleep(philo, result);
			usleep(500);
		}
	}
	return (0);
}

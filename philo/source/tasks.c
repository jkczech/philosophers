/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:27:06 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/17 20:25:02 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		message(*philo->data, FORK,
			philo_time() - philo->data->begin_time, philo->id);
		message(*philo->data, FORK,
			philo_time() - philo->data->begin_time, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		message(*philo->data, FORK,
			philo_time() - philo->data->begin_time, philo->id);
		message(*philo->data, FORK,
			philo_time() - philo->data->begin_time, philo->id);
	}
}

void	return_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eating(t_philo *philo)
{
	take_forks(philo);
	message(*philo->data, EATING,
		philo_time() - philo->data->begin_time, philo->id);
	pthread_mutex_lock(&philo->data->eating);
	philo->last_meal = philo_time();
	pthread_mutex_unlock(&philo->data->eating);
	ft_usleep(philo, philo->data->time_to_eat);
	return_forks(philo);
	if (philo->data->max_eat != -1)
	{
		pthread_mutex_lock(&philo->data->eating);
		philo->meal_count++;
		pthread_mutex_unlock(&philo->data->eating);
	}
}

void	sleeping(t_philo *philo)
{
	message(*philo->data, SLEEPING,
		philo_time() - philo->data->begin_time, philo->id);
	ft_usleep(philo, philo->data->time_to_sleep);
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

void	thinking(t_philo *philo)
{
	message(*philo->data, THINKING,
		philo_time() - philo->data->begin_time, philo->id);
	time_shift(philo);
}

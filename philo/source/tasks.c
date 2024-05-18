/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:27:06 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/18 18:12:51 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		message(philo, FORK, philo_time() - philo->data->begin_time);
		message(philo, FORK, philo_time() - philo->data->begin_time);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
		message(philo, FORK, philo_time() - philo->data->begin_time);
		message(philo, FORK, philo_time() - philo->data->begin_time);
	}
}

void	return_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	eating(t_philo *philo)
{
	take_forks(philo);
	message(philo, EATING, philo_time() - philo->data->begin_time);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->eating);
	philo->last_meal = philo_time();
	pthread_mutex_unlock(&philo->data->eating);
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
	message(philo, SLEEPING, philo_time() - philo->data->begin_time);
	ft_usleep(philo->data->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	message(philo, THINKING, philo_time() - philo->data->begin_time);
	time_shift(philo);
}

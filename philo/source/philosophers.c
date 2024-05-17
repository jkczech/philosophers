/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:21:40 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/17 23:38:14 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&data->philo[i].philo_thread,
				NULL, &routine, &data->philo[i]))
			return ;
		pthread_mutex_lock(&data->eating);
		data->philo[i].last_meal = philo_time();
		pthread_mutex_unlock(&data->eating);
		i++;
	}
	monitor_philos(data);
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(data->philo[i].philo_thread, NULL))
			return ;
		i++;
	}
}

void	*routine(void *philo_pass)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pass;
	if (philo->data->num_of_philo == 1)
		return (lonely_philo(philo));
	if (philo->id % 2 != 0)
		usleep(500);
	while (!someone_is_dead(philo))
	{
		eating(philo);
		if (ate_too_much(philo))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (finished_eating(philo->data));
}

void	*lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	message(philo, FORK, philo_time() - philo->data->begin_time);
	pthread_mutex_unlock(philo->left_fork);
	ft_usleep(philo, philo->data->time_to_die);
	return (NULL);
}

void	*finished_eating(t_data *data)
{
	pthread_mutex_lock(&data->eating);
	data->finished++;
	pthread_mutex_unlock(&data->eating);
	return (NULL);
}

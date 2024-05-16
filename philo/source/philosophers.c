/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:21:40 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/16 22:57:11 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_create(&data->philo[i].philo_thread, NULL, &routine, &data->philo[i]))
		{
			write(2, "Error: thread creation failed\n", 31);
			return ;
		}
		i++;
	}
	monitor_philos(data);
	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(data->philo[i].philo_thread, NULL))
		{
			write(2, "Error: thread join failed\n", 27);
			return ;
		}
		i++;
	}
}

void	*routine(void *philo)
{
	t_philo	*philo_data;

	philo_data = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(&philo_data->mutex);
		message(THINKING, philo_data->data->begin_time, philo_data->id);
		pthread_mutex_unlock(&philo_data->mutex);
		usleep(1000);
	}
	return (NULL);
}

void	monitor_philos(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->dying);
		if (data->dead)
			break ;
		pthread_mutex_unlock(&data->dying);
	}
}


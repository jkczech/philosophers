/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:37:49 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/17 23:38:50 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	monitor_philos(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->num_of_philo)
		{
			pthread_mutex_lock(&data->eating);
			if (data->finished == data->num_of_philo)
			{
				pthread_mutex_unlock(&data->philo[i].data->eating);
				return ;
			}
			pthread_mutex_unlock(&data->eating);
			if (dying(data, i))
				return ;
			usleep(300);
			i++;
		}
	}
}

bool	dying(t_data *data, int i)
{
	pthread_mutex_lock(&data->eating);
	if (philo_time() - data->philo[i].last_meal > data->time_to_die)
	{
		message(&data->philo[i], DIED, philo_time() - data->begin_time);
		pthread_mutex_lock(&data->dying);
		data->dead = true;
		pthread_mutex_unlock(&data->dying);
		pthread_mutex_unlock(&data->eating);
		return (true);
	}
	pthread_mutex_unlock(&data->eating);
	return (false);
}

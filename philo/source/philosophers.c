/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:21:40 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/16 23:26:47 by jkoupy           ###   ########.fr       */
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

void	*routine(void *philo_pass)
{
	t_philo	*philo;

	philo = (t_philo *)philo_pass;
	philo->last_meal = philo_time();
	while (!everyone_alive(philo) && !everyone_ate(philo))
	{
		take_forks(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
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


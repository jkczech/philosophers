/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:21:40 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/16 22:29:16 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_create(&data->philo[i].philo_thread, NULL, &routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(data->philo[i].philo_thread, NULL);
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


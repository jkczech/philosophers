/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 21:21:40 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/17 21:00:35 by jkoupy           ###   ########.fr       */
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
	pthread_mutex_lock(&philo->data->eating);
	philo->last_meal = philo_time();
	pthread_mutex_unlock(&philo->data->eating);
	if (philo->data->num_of_philo == 1)
	{
		lonely_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 != 0)
		usleep(500);
	while (!someone_is_dead(philo) && !ate_too_much(philo))
	{
		eating(philo);
		if (ate_too_much(philo))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (finished_eating(philo->data));
}

void	ft_usleep(t_philo *philo, int time)
{
	int	begin;

	begin = philo_time();
	(void)philo;
	while (philo_time() - begin < time)
	{
		/* if (someone_is_dead(philo) || ate_too_much(philo))
			return ; */
		usleep(150);
	}
}

void	lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	message(*philo->data, FORK, philo_time() - philo->data->begin_time,
		philo->id);
	pthread_mutex_unlock(philo->left_fork);
	ft_usleep(philo, philo->data->time_to_die);
}

void	monitor_philos(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->num_of_philo)
		{
			pthread_mutex_lock(&data->philo[i].data->eating);
			if (data->finished == data->num_of_philo)
			{
				//printf("All philosophers have eaten enough\n");
				pthread_mutex_unlock(&data->philo[i].data->eating);
				return ;
			}
			pthread_mutex_unlock(&data->philo[i].data->eating);
			pthread_mutex_lock(&data->philo[i].data->eating);
			if (philo_time() - data->philo[i].last_meal > data->time_to_die)
			{
				pthread_mutex_lock(&data->philo[i].data->dying);
				message(*data, DIED, philo_time() - data->begin_time,
					data->philo[i].id);
				data->dead = true;
				pthread_mutex_unlock(&data->philo[i].data->dying);
				pthread_mutex_unlock(&data->philo[i].data->eating);
				return ;
			}
			pthread_mutex_unlock(&data->philo[i].data->eating);
			usleep(300);
			i++;
		}
	}
}

void	*finished_eating(t_data *data)
{
	pthread_mutex_lock(&data->eating);
	data->finished++;
	pthread_mutex_unlock(&data->eating);
	return (NULL);
}
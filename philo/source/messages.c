/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:37:45 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/17 23:33:52 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	message(t_philo *philo, t_state state, int timestamp)
{
	pthread_mutex_lock(&philo->data->writing);
	if (!is_dead(philo->data))
	{
		if (state == FORK)
			printf("%d %d has taken a fork\n", timestamp, philo->id);
		else if (state == EATING)
			printf("%d %d is eating\n", timestamp, philo->id);
		else if (state == SLEEPING)
			printf("%d %d is sleeping\n", timestamp, philo->id);
		else if (state == THINKING)
			printf("%d %d is thinking\n", timestamp, philo->id);
		else if (state == DIED)
			printf("%d %d died\n", timestamp, philo->id);
	}
	pthread_mutex_unlock(&philo->data->writing);
}

bool	is_dead(t_data *data)
{
	pthread_mutex_lock(&data->dying);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->dying);
		return (true);
	}
	pthread_mutex_unlock(&data->dying);
	return (false);
}

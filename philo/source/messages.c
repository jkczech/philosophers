/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:37:45 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/17 19:30:03 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	message(t_data data, t_state state, int timestamp, int philo)
{
	pthread_mutex_lock(&data.dying);
	if (data.dead && state != DIED)
	{
		pthread_mutex_unlock(&data.dying);
		return ;
	}
	pthread_mutex_unlock(&data.dying);
	pthread_mutex_lock(&data.writing);
	if (state == FORK)
		printf("%d %d has taken a fork\n", timestamp, philo);
	else if (state == EATING)
		printf("%d %d is eating\n", timestamp, philo);
	else if (state == SLEEPING)
		printf("%d %d is sleeping\n", timestamp, philo);
	else if (state == THINKING)
		printf("%d %d is thinking\n", timestamp, philo);
	else if (state == DIED)
		printf("%d %d died\n", timestamp, philo);
	pthread_mutex_unlock(&data.writing);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:37:45 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/16 20:11:12 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	message(t_state state, int timestamp, int philo)
{
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
	else
		printf("Philosophers strike for more forks\n");
}
/* 
pthread_mutex_init(&data->philo[philo].mutex, NULL);
pthread_mutex_lock(&data->philo[philo].mutex);
pthread_t	philo_thread;
pthread_create(&philo_thread, NULL, &routine, &data->philo[philo]);
while(is_dead())
{
	is_dead=true;
	write(1, "Philosophers strike for more forks\n", 35);
	usleep(1000);
}


pthread_mutex_unlock(&data->philo[philo].mutex);

 */
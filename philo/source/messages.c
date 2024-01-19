/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:37:45 by jkoupy            #+#    #+#             */
/*   Updated: 2024/01/19 13:52:51 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	message(int mode, int timestamp, int philo)
{
	if (mode == FORK)
		printf("%d %d has taken a fork\n", timestamp, philo);
	else if (mode == EATING)
		printf("%d %d is eating\n", timestamp, philo);
	else if (mode == SLEEPING)
		printf("%d %d is sleeping\n", timestamp, philo);
	else if (mode == THINKING)
		printf("%d %d is thinking\n", timestamp, philo);
	else if (mode == DIED)
		printf("%d %d died\n", timestamp, philo);
	else
		printf("Philosophers strike for more forks\n");
}

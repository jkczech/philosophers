/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:19:04 by jkoupy            #+#    #+#             */
/*   Updated: 2024/01/19 13:53:08 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//memset
# include <string.h>
//printf
# include <stdio.h>
//malloc, free,
# include <stdlib.h>
//write, usleep
# include <unistd.h>
//gettimeofday
# include <sys/time.h>
// pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy
// pthread_mutex_lock, pthread_mutex_unlock
# include <pthread.h>

# define FORK 101
# define EATING 102
# define SLEEPING 103
# define THINKING 104
# define DIED 105

typedef struct s_philo
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_must_eat;
}	t_philo;

void    message(int mode, int timestamp, int philo);

#endif

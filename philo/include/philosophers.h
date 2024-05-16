/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:19:04 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/16 21:41:16 by jkoupy           ###   ########.fr       */
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
//bool
# include <stdbool.h>

typedef enum e_state
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED
}	t_state;

typedef struct s_philo
{
	int				id;
	int				num_of_times_eat;
	int				last_meal;
	t_state			state;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_must_eat;
	t_philo			*philo;
	int				begin_time;
	int				*is_dead;
	pthread_mutex_t	*forks;
}	t_data;

//main.c
int		main(int argc, char argv);

//checker.c
bool	check_args(int argc, char **argv);

//libft.c
int		ft_atoi(const char *nptr);
bool	ft_isdigit(int c);

//messages.c
void	message(t_state state, int timestamp, int philo);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:19:04 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/16 23:37:47 by jkoupy           ###   ########.fr       */
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
	pthread_t		philo_thread;
	int				id;
	int				meal_count;
	int				last_meal;
	t_state			state;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo			*philo;
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				begin_time;
	bool			dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writing;
	pthread_mutex_t	eating;
	pthread_mutex_t	dying;
}	t_data;

//checker.c
bool	check_args(int argc, char **argv);
bool	all_digit(int argc, char **argv);
bool	non_negative(int argc, char **argv);
bool	everyone_alive(t_philo *philo);
bool	everyone_ate(t_philo *philo);

//libft.c
int		ft_atoi(const char *nptr);
bool	ft_isdigit(int c);

//main.c
int		main(int argc, char **argv);
bool	init_data(t_data *data, int argc, char **argv);
int		philo_time(void);
bool	init_philos(t_data *data);
void	free_data(t_data *data);

//messages.c
void	message(t_state state, int timestamp, int philo);

//philosophers.c
void	philosophers(t_data *data);
void	*routine(void *philo);
void	monitor_philos(t_data *data);

//tasks.c
void	take_forks(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

#endif

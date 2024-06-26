/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:00:40 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/17 23:32:50 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		write(2, "Error: wrong number of arguments\n", 34);
		return (1);
	}
	if (!check_args(argc, argv))
		return (1);
	if (!init_data(&data, argc, argv) || !init_philos(&data))
		return (1);
	philosophers(&data);
	free_data(&data);
	return (0);
}

bool	init_data(t_data *data, int argc, char **argv)
{
	data->num_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->max_eat = -1;
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	data->finished = 0;
	data->dead = false;
	data->begin_time = philo_time();
	if (pthread_mutex_init(&data->writing, NULL))
		return (false);
	if (pthread_mutex_init(&data->eating, NULL))
	{
		pthread_mutex_destroy(&data->writing);
		return (false);
	}
	if (pthread_mutex_init(&data->dying, NULL))
	{
		pthread_mutex_destroy(&data->writing);
		pthread_mutex_destroy(&data->eating);
		return (false);
	}
	return (true);
}

bool	init_philos(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	if (!data->philo || !data->forks)
		return (false);
	i = 0;
	while (i < data->num_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].meal_count = 0;
		data->philo[i].last_meal = philo_time();
		data->philo[i].data = data;
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->num_of_philo];
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (true);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	free(data->philo);
	pthread_mutex_destroy(&data->writing);
	pthread_mutex_destroy(&data->eating);
	pthread_mutex_destroy(&data->dying);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 23:27:06 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/16 23:28:33 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex);
    pthread_mutex_lock(philo->left_fork);
    pthread_mutex_lock(philo->right_fork);
    pthread_mutex_unlock(&philo->mutex);
}

void    eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->writing);
    printf("%d %d is eating\n", philo_time() - philo->data->begin_time, philo->id);
    pthread_mutex_unlock(&philo->data->writing);
    philo->last_meal = philo_time();
    usleep(philo->data->time_to_eat * 1000);
    pthread_mutex_unlock(philo->left_fork);
    pthread_mutex_unlock(philo->right_fork);
    philo->meal_count++;
}

void    sleeping(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->writing);
    printf("%d %d is sleeping\n", philo_time() - philo->data->begin_time, philo->id);
    pthread_mutex_unlock(&philo->data->writing);
    usleep(philo->data->time_to_sleep * 1000);
}

void    thinking(t_philo *philo)
{
    pthread_mutex_lock(&philo->data->writing);
    printf("%d %d is thinking\n", philo_time() - philo->data->begin_time, philo->id);
    pthread_mutex_unlock(&philo->data->writing);
}
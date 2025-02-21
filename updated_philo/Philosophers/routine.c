/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 05:11:21 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 01:42:59 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void	update_philo_info(t_philo *philo)
{
	pthread_mutex_lock(philo->data->data_access + philo->id);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->data->data_access + philo->id);
}

int	philo_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (print_status(get_current_time(), philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	if (print_status(get_current_time(), philo, "has taken a fork"))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	if (print_status(get_current_time(), philo, "is eating"))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	update_philo_info(philo);
	ft_usleep(philo->data->time_to_eat, philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

void	philo_first_actions(t_philo *philo)
{
	pthread_mutex_lock(philo->data->data_access + philo->id);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(philo->data->data_access + philo->id);
	if (philo->id % 2 != 0)
		usleep(500);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	philo_first_actions(philo);
	while (1)
	{
		if (philo->data->num_philos == 1)
		{
			pthread_mutex_lock(philo->left_fork);
			print_status(get_current_time(), philo, "has taken a fork");
			while (ft_stop(philo) == false)
				;
			pthread_mutex_unlock(philo->left_fork);
			return (NULL);
		}
		if (philo_eating(philo))
			return (NULL);
		if (print_status(get_current_time(), philo, "is sleeping"))
			return (NULL);
		ft_usleep(philo->data->time_to_sleep, philo);
		if (print_status(get_current_time(), philo, "is thinking"))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:20:49 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 09:58:35 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

int	allocate_mutexes(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	data->write_lock = malloc(sizeof(pthread_mutex_t));
	data->death_lock = malloc(sizeof(pthread_mutex_t));
	data->data_access = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks || !data->write_lock || !data->death_lock
		|| !data->data_access)
		return (printf("Malloc Error \n"), 1);
	memset(data->forks, 0, sizeof(pthread_mutex_t) * data->num_philos);
	memset(data->write_lock, 0, sizeof(pthread_mutex_t));
	memset(data->death_lock, 0, sizeof(pthread_mutex_t));
	memset(data->data_access, 0, sizeof(pthread_mutex_t) * data->num_philos);
	return (0);
}

int	mutex_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			destroy_mutexes(data->forks, i);
			free(data->write_lock);
			free(data->death_lock);
			free(data->data_access);
			return (1);
		}
		i++;
	}
	return (0);
}

int	mutex_write(t_data *data)
{
	if (pthread_mutex_init(data->write_lock, NULL) != 0)
	{
		free(data->forks);
		free(data->write_lock);
		free(data->death_lock);
		free(data->data_access);
		return (1);
	}
	return (0);
}

int	mutex_death(t_data *data)
{
	if (pthread_mutex_init(data->death_lock, NULL) != 0)
	{
		free(data->forks);
		free(data->write_lock);
		free(data->death_lock);
		free(data->data_access);
		return (1);
	}
	return (0);
}

int	mutex_access(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->data_access[i], NULL) != 0)
		{
			destroy_mutexes(data->data_access, i);
			free(data->forks);
			free(data->write_lock);
			free(data->death_lock);
			free(data->data_access);
			return (1);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:12:43 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 09:10:59 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void	destroy_mutexes(pthread_mutex_t *mutexes, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (mutexes + i)
			pthread_mutex_destroy(mutexes + i);
		i++;
	}
	free(mutexes);
}

void	clear_data(t_data *data)
{
	if (data->death_lock)
	{
		pthread_mutex_destroy(data->death_lock);
	}
	if (data->write_lock)
		pthread_mutex_destroy(data->write_lock);
	if (data->forks)
		destroy_mutexes(data->forks, data->num_philos);
	free(data->write_lock);
	free(data->death_lock);
	free(data->data_access);
}

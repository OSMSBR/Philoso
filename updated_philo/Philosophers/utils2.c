/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:32:24 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 03:53:36 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

int	print_status(int time, t_philo *philo, char *state)
{
	if (ft_stop(philo) == true)
	{
	    printf("Philosopher %d stopped before printing\n", philo->id);
	    return (1);
	}
	pthread_mutex_lock(philo->data->write_lock);
	if (ft_stop(philo) == true)
	{
		pthread_mutex_unlock(philo->data->write_lock);
		return (1);
	}
	printf("%lu %u %s\n", time - philo->data->start_time, philo->id, state);
	pthread_mutex_unlock(philo->data->write_lock);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds, t_philo *philos)
{
	size_t	start;
	size_t	end;
	(void)philos;

	start = get_current_time();
	end = 0;
	while (end < milliseconds)
	{
		end = get_current_time() - start;
		usleep(500);
	}
	return (0);
}
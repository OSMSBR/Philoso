/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:58:35 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 09:47:03 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

void	assign_forks(t_philo **philo, t_data *data, int i)
{
	if (i % 2 == 0)
	{
		(*philo)[i].left_fork = &data->forks[i];
		(*philo)[i].right_fork = &data->forks[(i + 1) % data->num_philos];
	}
	else
	{
		(*philo)[i].left_fork = &data->forks[(i + 1) % data->num_philos];
		(*philo)[i].right_fork = &data->forks[i];
	}
}

t_philo	*ft_philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->num_philos);
	if (!philo)
		return (NULL);
	memset(philo, 0, sizeof(t_philo) * data->num_philos);
	while (i < data->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].meals_eaten = 0;
		philo[i].philo_thread = 0;
		philo[i].last_meal_time = get_current_time();
		assign_forks(&philo, data, i);
		i++;
	}
	return (philo);
}

int	ft_data_init(t_data *data, int noa, char *input[])
{
	data->num_philos = ft_atoi(input[1]);
	data->time_to_die = ft_atoi(input[2]);
	data->time_to_eat = ft_atoi(input[3]);
	data->time_to_sleep = ft_atoi(input[4]);
	data->dead = 0;
	if (noa == 6)
		data->meals_to_eat = ft_atoi(input[5]);
	else
		data->meals_to_eat = -1;
	if (allocate_mutexes(data) != 0)
		return (1);
	if (mutex_forks(data) != 0)
		return (1);
	if (mutex_write(data) != 0)
		return (1);
	if (mutex_death(data) != 0)
		return (1);
	if (mutex_access(data) != 0)
		return (1);
	else
		return (0);
}

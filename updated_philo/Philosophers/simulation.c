/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:30:24 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 03:51:52 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

bool	ft_stop(t_philo *philo)
{
	bool	stop;

	pthread_mutex_lock(philo->data->death_lock);
	stop = philo->data->dead;
	pthread_mutex_unlock(philo->data->death_lock);
	return (stop);
}
void	ft_set_stop(t_philo *philo, int philo_id)
{
	pthread_mutex_lock(philo->data->write_lock);
	pthread_mutex_lock(philo->data->death_lock);
	philo->data->dead = true;
	pthread_mutex_unlock(philo->data->death_lock);
	if (philo_id != -1)
		printf("%lu %u died\n", get_current_time() - philo->data->start_time, philo_id + 1);
	pthread_mutex_unlock(philo->data->write_lock);
}

int ft_checker(t_philo **philo)
{
    int philos_ate;
    int i;
    
    while(!(ft_stop(*philo)))
    {
        i = 0;
        philos_ate = 0;
        while(i < (*philo)->data->num_philos)
        {
            pthread_mutex_lock(&(*philo)->data->data_access[i]);
            if(get_current_time() - (*philo)[i].last_meal_time > (unsigned long)(*philo)->data->time_to_die)
            {
                ft_set_stop(*philo , i);
                pthread_mutex_unlock(&(*philo)->data->data_access[i]);
                return 1;
            }
            if((*philo)[i].meals_eaten >= (*philo)->data->meals_to_eat)
                philos_ate++;
            pthread_mutex_unlock(&(*philo)->data->data_access[i]);
        }
        if(philos_ate == (*philo)->data->num_philos)
            ft_set_stop(*philo, -1);
    }
    return 0;
}
int	create_philos(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->num_philos)
	{
		philo->last_meal_time = get_current_time();
		if (pthread_create(&philo[i].philo_thread, NULL, routine,
				&philo[i]) != 0)
			return (1);
        // printf("Creating philosopher %d\n", i + 1);
		i++;
	}
	return (0);
}
void    ft_start(t_philo **philo)
{
    int i;

    i = 0;
    (*philo)->data->start_time = get_current_time();
    if(create_philos(*philo))
    {
        ft_set_stop(*philo, -1);
        while(i < (*philo)->data->num_philos)
        {
            if((*philo)[i].philo_thread)
                pthread_join((*philo)[i].philo_thread , NULL);
            i++;
        }
    }
        ft_checker(philo);
    return;
}
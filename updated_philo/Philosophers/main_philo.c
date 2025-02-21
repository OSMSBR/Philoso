/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:34:32 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 01:39:52 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

int main(int argc , char *argv[])
{
    // pthread_t   check_thread;
    t_data      program_data;
    t_philo     *philos;

    philos = NULL;

    if(parse(argc, argv) != 0)
        return 1;
    if(ft_data_init(&program_data ,argc , argv) != 0)
        return 1;
    // printf("time to die : %d\n",program_data.time_to_die);
    // printf("time to eat : %d\n",program_data.time_to_eat);
    // printf("time to sleep : %d\n",program_data.time_to_sleep);
    // printf("number of philos  : %d\n",program_data.num_philos);
    philos = ft_philo_init(&program_data);
    if(NULL == philos)
        return 1;
    // printf(" philo id is : %d\n",philos[1].id);
    // printf(" philo last meal : %ld\n",philos->last_meal_time);
    ft_start(&philos);
    clear_data(&program_data);

    
}


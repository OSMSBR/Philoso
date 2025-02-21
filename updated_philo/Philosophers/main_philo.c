/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:34:32 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 06:01:44 by osebbar          ###   ########.fr       */
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
    philos = ft_philo_init(&program_data);
    if(NULL == philos)
        return 1;
    ft_start(&philos);
    // clear_data(&program_data);

    
}


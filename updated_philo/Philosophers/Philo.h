/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:32:21 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 04:27:19 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>

typedef struct s_data
{
    bool                dead;
    int                 time_to_sleep;
    int                 time_to_die;
    int                 time_to_eat;
    int                 meals_to_eat;
    int                 num_philos;
    long                start_time;
    pthread_mutex_t     *forks;
    pthread_mutex_t     *data_access;
    pthread_mutex_t     *death_lock;
    pthread_mutex_t     *write_lock;
    
}           t_data;


typedef struct s_philo
{
    int                 id;
    long                last_meal_time;
    int                 meals_eaten;
    t_data              *data;
    pthread_t           philo_thread;
    pthread_mutex_t     *right_fork;
    pthread_mutex_t     *left_fork;
    
}           t_philo;



//// FUNCTIONS //////

int         ft_atoi(char *str);
int	        ft_isdigit(int c);
int         check_input(char *input);
int         philo_routine(void *arg);
int         parse(int noa ,char **input);
int         ft_usleep(size_t milliseconds, t_philo *philos);
int         ft_data_init(t_data *data, int argc, char *input[]);
int        print_status(size_t time, t_philo *philo, char *state);
void	    *routine(void *args);
bool	    ft_stop(t_philo *philo);
void	    clear_data(t_data *data);
void*       monitor_philos(void *arg);
void        ft_start(t_philo **philo);
void	    destroy_mutexes(pthread_mutex_t *mutexes, int n);
void        assign_forks(t_philo **philo, t_data *data , int i);
size_t	    get_current_time(void);
t_philo*    ft_philo_init(t_data *program_data);




#endif 
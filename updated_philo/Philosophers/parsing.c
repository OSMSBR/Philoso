/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osebbar <osebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:36:49 by osebbar           #+#    #+#             */
/*   Updated: 2025/02/21 09:13:23 by osebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philo.h"

int	parse(int noa, char *str[])
{
	int	i;

	i = 1;
	if (noa != 5 && noa != 6)
	{
		printf(" The program takes 5-6 parameters :\n");
		printf("<Number of philos> \n<Time to die>");
		printf("<Time to eat>\n <Time to sleep> \n<Number of meals>\n");
		return (1);
	}
	if (ft_atoi(str[1]) > 200)
	{
		printf("Number of philos must not exceed 200 !\n");
		return (1);
	}
	while (i < noa)
	{
		if (check_input(str[i]) != 0 || ft_atoi(str[i]) <= 0)
		{
			printf("Enter valid arguments !\n");
			return (1);
		}
		i++;
	}
	return (0);
}

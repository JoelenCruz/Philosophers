/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:57:06 by joe               #+#    #+#             */
/*   Updated: 2023/09/14 13:02:03 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"


int ft_atoi(char *str)
{
    int i = 0;
    int negative = 1;
    int result = 0;

    while(str[i] <= 32)
        i++;
    
    if(str[i] == '-')
    {
        negative = -1;
        i++;
    }

    while (str[i] == '-' || str[i] == '+')
        i++;

    while(str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return(result *negative); 
}


void init_all_philos (t_all_philos *s_all_philos)
{
    s_all_philos->number_of_philosophers = 0;
    s_all_philos->time_to_die = 0;
    s_all_philos->time_to_eat = 0;
    s_all_philos->time_to_sleep = 0;
    s_all_philos->number_of_times_each_philosopher_must_eat = 0;
}
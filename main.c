/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:57:19 by joe               #+#    #+#             */
/*   Updated: 2023/09/14 12:57:50 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

//TODO--> create makefilen (ok)

//TODO---> create check for acetps types. 

//TODO--> create sub sctructure for each Philosophers

// • Your(s) program(s) should take the following arguments:

//! number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

// !number_of_philosophers: 
//The number of philosophers and also the number
// of forks.

// !time_to_die (in milliseconds): 
//If a philosopher didn’t start eating time_to_die
// milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

// !time_to_eat (in milliseconds): 
// The time it takes for a philosopher to eat.
// During that time, they will need to hold two forks.

// !time_to_sleep (in milliseconds): 
// The time a philosopher will spend sleeping.

// !number_of_times_each_philosopher_must_eat (optional argument): 
// If all
// philosophers have eaten at least number_of_times_each_philosopher_must_eat
// times, the simulation stops. If not specified, the simulation stops when a
// philosopher dies.


int main (int ac, char **av)
{
    t_all_philos s_all_philos;
    init_all_philos(&s_all_philos);
    if(ac == 5)
    {
        s_all_philos.number_of_philosophers = ft_atoi(av[1]);
        s_all_philos.time_to_die = ft_atoi(av[2]);
        s_all_philos.time_to_eat = ft_atoi(av[3]);
        s_all_philos.time_to_sleep = ft_atoi(av[4]);

        printf("#-#-#-#-#-#-#-#-#-#-#-#-#\n");
        printf("number_of_philosophers --> %i\n", s_all_philos.number_of_philosophers);
        printf("time_to_die --> %i\n", s_all_philos.time_to_die);
        printf("time_to_eat --> %i\n", s_all_philos.time_to_eat);
        printf("time_to_sleep --> %i\n", s_all_philos.time_to_sleep);
    }

    else if(ac == 6)
    {
        s_all_philos.number_of_philosophers = ft_atoi(av[1]);
        s_all_philos.time_to_die = ft_atoi(av[2]);
        s_all_philos.time_to_eat = ft_atoi(av[3]);
        s_all_philos.time_to_sleep = ft_atoi(av[4]);
        s_all_philos.number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);

        printf("#-#-#-#-#-#-#-#-#-#-#-#-#\n");
        printf("number_of_philosophers --> %i\n", s_all_philos.number_of_philosophers);
        printf("time_to_die --> %i\n", s_all_philos.time_to_die);
        printf("time_to_eat --> %i\n", s_all_philos.time_to_eat);
        printf("time_to_sleep --> %i\n", s_all_philos.time_to_sleep);
        printf("number_of_times_each_philosopher_must_eat--> %i\n", s_all_philos.number_of_times_each_philosopher_must_eat);
    }
    else
        printf("numero de parametros incorreto!\n");

    return (0);  
}
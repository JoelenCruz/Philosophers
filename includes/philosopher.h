/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:00:18 by joe               #+#    #+#             */
/*   Updated: 2023/09/14 13:04:22 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H


#include <stdio.h>




// =============================================================================
// STRUCTS
// =============================================================================
/**
 * @brief This struct for crate philosophes
 * 
 */

typedef struct s_all_philos
{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat; 
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;

}t_all_philos;


// =============================================================================
// FUNCTIONS
// =============================================================================

/**
 * Converts a string to an integer.
 *
 * This function takes a string `str` and converts it to an integer.
 *
 * @param str The string to be converted.
 * @return The resulting integer value from the conversion.
 */
int ft_atoi(char *str);

/**
 * Initializes a structure of type t_all_philos.
 *
 * This function initializes a structure of type `t_all_philos` with default values.
 * The `t_all_philos` structure typically represents a set of parameters for a philosopher's simulation.
 *
 * @param s_all_philos A pointer to the `t_all_philos` structure to be initialized.
 */
void init_all_philos (t_all_philos *s_all_philos);


#endif
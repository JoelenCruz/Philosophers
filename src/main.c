/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:57:19 by joe               #+#    #+#             */
/*   Updated: 2023/10/07 15:15:44 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		print_error();
	else if (check_num(av))
		print_error();
	else if (ft_atol(av[1]) < 1 || ft_atol(av[1]) > 200)
		print_error();
	else if (ac == 6 && ft_atol(av[5]) <= 0)
		print_error();
	else
		while (++i < 5)
			if (ft_atol(av[i]) < 60)
				print_error();
	if (philosophers(ac, av) != 0)
		return (EXIT_FAILURE);
	return (0);
}

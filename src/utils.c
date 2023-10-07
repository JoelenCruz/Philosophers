/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:57:06 by joe               #+#    #+#             */
/*   Updated: 2023/10/07 15:23:03 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}

int	check_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int(long long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
	{
		printf(YELLOW_TEXT ERRO_INT_MAX_MIN RESET_COLOR);
		return (1);
	}
	return (0);
}

long long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	nbr *= sign;
	return (nbr);
}

int	print_error(void)
{
	printf("\n");
	printf(RED_TEXT "Invalid argument!\n" RESET_COLOR);
	printf("Examples:\n");
	printf("./philo 4 400 200 200 5\n");
	printf("./philo 4 400 200 200\n");
	printf("\n");
	printf(YELLOW_TEXT "Rules:\n" RESET_COLOR);
	printf("av[0] = program name: ./philo\n");
	printf("av[1] = number_philos: 1-200\n");
	printf("av[2] = time_to_die: 60+\n");
	printf("av[3] = time_to_eat: 60+\n");
	printf("av[4] = time_to_sleep: 60+\n");
	printf("av[5] = number_of_times_each_philosopher_must_eat: 0+\n ");
	printf("\n");
	exit (1);
}

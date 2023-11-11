/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:43:45 by joe               #+#    #+#             */
/*   Updated: 2023/11/11 11:41:00 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	ft_sleep(t_data_each_philos *philo)
{
	set_philo_state(philo, SLEEPING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(philo->info_philos, philo->id, SLEEP);
	ft_usleep(get_sleep_time(philo->info_philos));
	return (0);
}

void	ft_usleep(uint64_t sleep_time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(500);
}

int	think(t_data_each_philos *philo)
{
	u_int64_t	time_eat;
	u_int64_t	time_sleep;

	set_philo_state(philo, THINKING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(philo->info_philos, philo->id, THINK);
	time_eat = get_eat_time(philo->info_philos);
	time_sleep = get_sleep_time(philo->info_philos);
	if (time_eat >= time_sleep)
		usleep(((time_eat - time_sleep) * 1000) + 500);
	return (0);
}

bool	philo_died(t_data_each_philos *philo)
{
	bool				result;
	t_info_philos		*data;

	data = philo->info_philos;
	result = false;
	if (get_time() - get_last_eat_time(philo) > get_die_time(data)
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		result = true;
	}
	return (result);
}

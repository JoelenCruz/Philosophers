/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:22:00 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/11/11 11:55:14 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int	run_threads(t_info_philos *info_philos)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = get_nb_philos(info_philos);
	i = -1;
	info_philos->start_time = get_time();
	while (++i < nb_of_philos)
	{
		if (pthread_create(&info_philos->philo_ths[i], NULL,
				&routine, &info_philos->philos[i]))
			return (1);
	}
	if (pthread_create(&info_philos->monit_all_alive, NULL,
			&all_alive_routine, info_philos))
		return (1);
	if (nb_meals_option(info_philos) == true
		&& pthread_create(&info_philos->monit_all_full, NULL,
			&all_full_routine, info_philos))
		return (1);
	return (0);
}

int	join_threads(t_info_philos *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (nb_meals_option(data) == true
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

int	just_one_philo(t_data_each_philos *philo)
{
	take_left_fork(philo);
	ft_usleep(get_die_time(philo->info_philos));
	set_philo_state(philo, DEAD);
	drop_left_fork(philo);
	return (1);
}

void	set_keep_iterating(t_info_philos *data, bool set_to)
{
	pthread_mutex_lock(&data->mut_keep_iter);
	data->keep_iterating = set_to;
	pthread_mutex_unlock(&data->mut_keep_iter);
}

void	set_philo_state(t_data_each_philos *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}

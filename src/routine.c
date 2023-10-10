/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:24:39 by joe               #+#    #+#             */
/*   Updated: 2023/10/07 15:12:19 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	notify_all_philos(t_info_philos *info_philos)
{
	t_data_each_philos		*philos;
	int						i;
	int						nb_philos;

	nb_philos = get_nb_philos(info_philos);
	philos = info_philos->philos;
	i = -1;
	while (++i < nb_philos)
		set_philo_state(&philos[i], DEAD);
}

void	*all_full_routine(void *data_p)
{
	t_info_philos	*data;
	int				i;
	int				nb_philos;

	data = (t_info_philos *)data_p;
	i = -1;
	nb_philos = get_nb_philos(data);
	while (++i < nb_philos && get_keep_iter(data))
	{
		usleep(1000);
		if (is_philo_full(data, &data->philos[i]) == false)
			i = -1;
	}
	if (get_keep_iter(data) == true)
	{
		set_keep_iterating(data, false);
		notify_all_philos(data);
	}
	return (NULL);
}

void	*all_alive_routine(void *data_p)
{
	int					i;
	int					nb_philos;
	t_info_philos		*data;
	t_data_each_philos	*philos;

	data = (t_info_philos *)data_p;
	philos = data->philos;
	nb_philos = get_nb_philos(data);
	i = -1;
	while (++i < nb_philos && get_keep_iter(data))
	{
		if (philo_died(&philos[i]) && get_keep_iter(data))
		{
			print_msg(data, philos[i].id, DIED);
			set_keep_iterating(data, false);
			notify_all_philos(data);
			break ;
		}
		if (i == nb_philos - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}

void	*routine(void *philo_p)
{
	t_data_each_philos	*philo;

	philo = (t_data_each_philos *) philo_p;
	update_last_meal_time(philo);
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}

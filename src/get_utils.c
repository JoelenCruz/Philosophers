/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:53:04 by joe               #+#    #+#             */
/*   Updated: 2023/10/07 15:13:59 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

bool	nb_meals_option(t_info_philos *data)
{
	if (data->nb_meals > 0)
		return (true);
	return (false);
}

void	print_nb_meals_had(t_data_each_philos *philo)
{
	t_info_philos	*data;

	data = philo->info_philos;
	pthread_mutex_lock(&data->mut_print);
	printf("Philo %d ate %d times\n", philo->id, philo->nb_meals_had);
	pthread_mutex_unlock(&data->mut_print);
}

void	print_msg(t_info_philos *data, int id, char *msg)
{
	uint64_t	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data->mut_print);
	if (get_keep_iter(data))
		printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}

void	print_mut(t_info_philos *data, char *msg)
{
	pthread_mutex_lock(&data->mut_print);
	printf("%s\n", msg);
	pthread_mutex_unlock(&data->mut_print);
}

void	free_data(t_info_philos *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals_had);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_keep_iter);
	pthread_mutex_destroy(&data->mut_start_time);
	free(data->philo_ths);
	free(data->philos);
	free(data->forks);
}

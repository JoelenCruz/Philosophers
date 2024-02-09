/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:00:18 by joe               #+#    #+#             */
/*   Updated: 2023/11/11 11:58:23 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

//! =========================================================================
//! INCLUDES
//! =========================================================================
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>
# include <stdint.h> //u_int64_t

//! ==========================================================================
//! COLORS
//! ==========================================================================
# define RED_TEXT     "\033[0;31m"
# define GREEN_TEXT   "\033[0;32m"
# define YELLOW_TEXT  "\033[0;33m"
# define RESET_COLOR  "\033[0m"

//! =========================================================================
//! MACROS
//! =========================================================================
# define ERROR_INVAL "Error: Invalid arguments\n" 
# define ERROR_INSU "Error: Insufficient arguments\n" 
# define ERROR_MAX "Error: The number of arguments exceeds the expected value\n" 
# define ERRO_INT_MAX_MIN "Error: the max/min integer has been exceeded\n"
# define EXIT_FAILURE	1	/* Failing exit status.  */
# define EXIT_SUCCESS	0	/* Successful exit status.  */
# define TAKE_FORKS "has taken a fork"
# define TAKE_FORKS_LEFT "has taken a fork (left 🍴)"
# define TAKE_FORKS_RIGHT "has taken a fork (right 🍴)"

# define EAT "is eating 🍝" 
# define SLEEP "is sleeping 😴"
# define THINK "is thinking 💭"
# define DIED "died 💀"

//! ==========================================================================
//! STRUCTS
//! ==========================================================================
typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}t_state;

typedef struct s_data_each_philos
{
	int						id;
	int						nb_meals_had;
	struct s_info_philos	*info_philos;
	t_state					state;
	u_int64_t				last_eat_time;
	pthread_mutex_t			*left_f;
	pthread_mutex_t			*right_f;
	pthread_mutex_t			mut_state;
	pthread_mutex_t			mut_nb_meals_had;
	pthread_mutex_t			mut_last_eat_time;
}t_data_each_philos;

typedef struct s_info_philos
{
	bool				keep_iterating;
	int					nb_philos;
	int					nb_meals;
	int					nb_full_p;
	u_int64_t			eat_time;
	u_int64_t			die_time;
	u_int64_t			sleep_time;
	u_int64_t			start_time;
	pthread_mutex_t		mut_eat_t;
	pthread_mutex_t		mut_die_t;
	pthread_mutex_t		mut_sleep_t;
	pthread_mutex_t		mut_print;
	pthread_mutex_t		mut_nb_philos;
	pthread_mutex_t		mut_keep_iter;
	pthread_mutex_t		mut_start_time;
	pthread_t			monit_all_alive;
	pthread_t			monit_all_full;
	pthread_t			*philo_ths;
	pthread_mutex_t		*forks;
	t_data_each_philos	*philos;
}t_info_philos;

//! ==========================================================================
//! FUNCTIONS
//! ==========================================================================

//!ultis.c
long long	ft_atol(const char *str);
int			ft_isdigit(int character);
void		print_jo(t_info_philos *s_info_philos);
int			check_int(long long nbr);
int			check_num(char **str);
int			print_error(void);
int			error_arg_max_min(int argc, char **argv);

//!init.c
int			copy_value_philo(t_info_philos *s_info_philos, int ac, char **av);
int			init_forks(t_info_philos *s_info_philos);
int			init_philos(t_info_philos *info_philos);
int			malloc_data_pointers(t_info_philos *info_philos);
int			philosophers(int argc, char **argv);

//!rotine.c
void		notify_all_philos(t_info_philos *data);
void		*all_full_routine(void *data_p);
void		*all_alive_routine(void *data_p);
void		*routine(void *philo_p);

//!threads.c
int			run_threads(t_info_philos *data);
int			join_threads(t_info_philos *data);
int			just_one_philo(t_data_each_philos *philo);
void		set_keep_iterating(t_info_philos *data, bool set_to);
void		set_philo_state(t_data_each_philos *philo, t_state state);

//!actions_eat.c
bool		is_philo_full(t_info_philos *data, t_data_each_philos *philo);
void		update_last_meal_time(t_data_each_philos *philo);
void		update_nb_meals_had(t_data_each_philos *philo);
void		sleep_for_eating(t_data_each_philos *philo);
int			eat(t_data_each_philos *philo);

//!action.c
int			ft_sleep(t_data_each_philos *philo);
void		ft_usleep(uint64_t sleep_time);
int			think(t_data_each_philos *philo);
bool		philo_died(t_data_each_philos *philo);

//!forks.c
void		drop_left_fork(t_data_each_philos *philo);
void		drop_right_fork(t_data_each_philos *philo);
int			take_left_fork(t_data_each_philos *philo);
int			take_right_fork(t_data_each_philos *philo);
int			take_forks(t_data_each_philos *philo);

//!time.c
uint64_t	get_start_time(t_info_philos *data);
uint64_t	get_die_time(t_info_philos *data);
uint64_t	get_sleep_time(t_info_philos *data);
uint64_t	get_eat_time(t_info_philos *data);
uint64_t	get_last_eat_time(t_data_each_philos *philo);

//!get_utils.c
bool		nb_meals_option(t_info_philos *data);
void		print_msg(t_info_philos *data, int id, char *msg);
void		free_data(t_info_philos *data);

//!get_utils_2.c
bool		get_keep_iter(t_info_philos *data);
int			get_nb_philos(t_info_philos *data);
t_state		get_philo_state(t_data_each_philos *philo);
int			get_nb_meals_philo_had(t_data_each_philos *philo);
u_int64_t	get_time(void);

#endif

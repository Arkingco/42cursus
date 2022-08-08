/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:55:06 by kipark            #+#    #+#             */
/*   Updated: 2022/08/08 16:58:38 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define ONE_MALLOC 1
# define ALL_PHILO_NUMBER 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define MUST_EAT_NUMBER 4
# define MAX_ARGC_SIZE 5

typedef struct timeval	t_timeval;

typedef struct s_philo_info
{
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*die_mutex;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	*all_eat_mutex;
	t_timeval		start_time;
	t_timeval		last_eat;
	int				*die_flag;
	int				index;
	int				*get_parse;
	int				eat_count;
	int				*all_eat_count;
}	t_philo_info;

typedef struct s_philo_monitor_info
{
	pthread_t		*philosophers_thread;
	t_philo_info	*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*die_mutex;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	*all_eat_mutex;
	int				*die_flag;
	int				*get_parse;
	int				*all_eat_count;
	int				all_philo_number;
	t_timeval		start_time;
}	t_philo_monitor_info;

// philo_mutex_get_set.c
void		set_last_eat(pthread_mutex_t *eat_mutex, t_timeval *last_eat);
int			check_philo_last_eat(t_philo_monitor_info *monitor, \
										t_timeval *last_eat, int time_to_die);
int			check_count_all_eat_mutex_flag(pthread_mutex_t *all_eat_mutex, \
									int *all_eat_count, int all_philo_number);
void		up_count_all_eat_mutex_flag(pthread_mutex_t *all_eat_mutex, \
															int *all_eat_count);
// error*.c
int			paser_error(char **need_parsed);
int			print_error(int exit_flag);

// utils
long int	parse_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);

// thread
void		run_thread(int *get_parse);
void		*philo_run(void *philos);
void		*philo_all_eat_wait(void *philos);

// parse
int			*parse(int argc, char **argv);

// philo_init
void		philo_malloc(t_philo_monitor_info *monitor, void *philos);
void		philo_init(t_philo_monitor_info *monitor);
void		philo_wait_and_free(t_philo_monitor_info *monitor, \
													pthread_t *all_eat_wait);

// philo_utils
void		philo_lock_forks(t_philo_info *this_philo, int philo_index);
void		philo_unlock_forks(t_philo_info *this_philo);
void		ms_usleep(int ms_second);
void		philo_print(t_philo_info *this_philo, char *strs);
long		get_diff_time(t_timeval start_time);

// philo_die
void		set_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag);
int			check_philo_die(t_philo_info *this_philo);
int			check_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag);

#endif
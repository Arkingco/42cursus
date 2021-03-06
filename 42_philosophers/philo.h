/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:55:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/29 15:25:17 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define NOTTING_ACTION -1
# define ONE_MALLOC 1
# define ALL_PHILO_NUMBER 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define MUST_EAT_NUMBER 4

typedef struct timeval timeval;

typedef struct s_philo_info
{
	pthread_mutex_t *fork_left;
	pthread_mutex_t *fork_right;
	pthread_mutex_t	*die_mutex;
	int				die_flag;
	timeval			start_time;
	timeval			last_eat;
	int				index;
	int				*get_parse;
}  	t_philo_info;

typedef	struct	s_philo_monitor_info
{
	pthread_t		*philosophers_thread;
	t_philo_info	*philosophers;
	pthread_mutex_t *forks;
	pthread_mutex_t	*die_mutex;
	timeval			start_time;
	int				*die_flag;
	int				*get_parse;
}	t_philo_monitor_info;

// error*
int			paser_error(char **need_parsed);
void		print_error(int exit_flag);

// utils
long int	parse_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);

// main
void		run_thread(int *get_parse);
int			*parse(int argc, char **argv);

void		*philo_run(void *philos);

// philo_init
void		philo_malloc(t_philo_monitor_info *monitor, void *philos);
void		philo_init(t_philo_monitor_info *monitor);
void		philo_wait_and_free(t_philo_monitor_info *monitor);

// philo_utils
void		philo_lock_forks(t_philo_info *this_philo, timeval start_time, int philo_index);
void		philo_unlock_forks(t_philo_info *this_philo);
void		ms_usleep(int ms_second);
void		philo_print(timeval start_time, int index, char *strs);
int			get_diff_time(int start_time);
int			get_time_to_int(timeval time);


// philo_die
void		set_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag);
int			check_philo_die(t_philo_info *this_philo, int action_flag);
int			check_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag);

# endif
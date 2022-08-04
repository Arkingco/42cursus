/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:55:06 by kipark            #+#    #+#             */
/*   Updated: 2022/08/04 22:02:43 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <string.h>

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
	sem_t		*forks;
	sem_t		*die_sem;
	sem_t		*eat_sem;
	t_timeval	start_time;
	t_timeval	last_eat;
	int			*die_flag;
	int			index;
	int			eat_count;
	int			*get_parse;
}	t_philo_info;

typedef struct s_philo_monitor_info
{
	pthread_t		*philosophers_thread;
	t_philo_info	*philosophers;
	sem_t			*forks;
	sem_t			*die_sem;
	sem_t			*eat_sem;
	sem_t			*all_eat_sem;
	int				*die_flag;
	int				*get_parse;
	int				index;
	int				all_philo_number;
	t_timeval		start_time;
}	t_philo_monitor_info;

typedef struct s_philo_main_monitor_info
{
	sem_t			*forks;
	sem_t			*die_sem;
	sem_t			*eat_sem;
	sem_t			*all_eat_sem;
}	t_philo_main_monitor_info;


void	set_last_eat(sem_t *eat_sem, t_timeval *last_eat);
int		check_philo_last_eat(t_philo_monitor_info *monitor, t_timeval *last_eat, int time_to_die);



// error*
int			paser_error(char **need_parsed);
int			print_error(int exit_flag);

// utils
long int	parse_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
// char		*ft_itoa(int n);
// char		*ft_strjoin(char const *s1, char const *s2);

// thread
void		run_thread(int *get_parse);
void		*philo_run(void *philos);

// parse
int			*parse(int argc, char **argv);

// philo_init
void		philo_malloc(t_philo_main_monitor_info *main_monitor, \
						t_philo_monitor_info *monitor, int index, void *philos);
void		philo_init(t_philo_monitor_info *monitor, int index);
void		philo_wait_and_free(t_philo_monitor_info *monitor);

// philo_utils
void		philo_lock_forks(t_philo_info *this_philo);
void		philo_unlock_forks(t_philo_info *this_philo);
void		ms_usleep(int ms_second);
void		philo_print(t_philo_info *this_philo, char *strs);
long		get_diff_time(t_timeval start_time);
sem_t		*make_semaphore(char *str, int count);
void 		printf_test(char * str);

// philo_die
void		set_die_sem_flag(sem_t *die_sem, int *die_flag);
int			check_philo_die(t_philo_info *this_philo);
int			check_die_sem_flag(sem_t *die_sem, int *die_flag);

#endif
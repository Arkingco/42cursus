/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:55:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/24 16:56:08 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

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
	int				my_philo_index;
	int				*get_parse;
}  	t_philo_info;
// typedef	struct s_philo_monitor
// {
// 	pthread_t		*philpsophers_thread;
// 	t_philo_info	*philpsophers;
// 	pthread_mutex_t *forks;
// }

// error*
int			paser_error(char **need_parsed);
void		print_error(int exit_flag);

// utils
long int	parse_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
void		ms_usleep(unsigned int ms_second);

// main
void		run_thread(int *get_parse);
int			*parse(int argc, char **argv);

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/28 17:06:27 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag)
{
	pthread_mutex_lock(die_mutex);
	*die_flag = 1;
	pthread_mutex_unlock(die_mutex);
}

int		check_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag)
{
	pthread_mutex_lock(die_mutex);
	if (*die_flag == 1)
		return (0);
	pthread_mutex_unlock(die_mutex);
	return (1);
}

void	philo_print(timeval start_time, t_philo_info *this_philo, char *strs)
{
	int diff_time;

	diff_time = get_diff_time(start_time);
	printf("%04d %d %s", diff_time, this_philo->index, strs);
}


void	philo_action_and_print(timeval start_time, t_philo_info *this_philo, char *strs, int action_flag)
{
	int	before_lats_time;

	before_lats_time = get_diff_time(this_philo->last_eat);
	
	if (before_lats_time >= this_philo->get_parse[TIME_TO_DIE])
			set_die_mutex_flag(this_philo->die_mutex, this_philo->die_flag);
	if (check_die_mutex_flag(this_philo->die_mutex, this_philo->die_flag) == 0)
		return ;
	philo_print(start_time, this_philo, strs);
	if (action_flag != 0)
		ms_usleep(this_philo->get_parse[action_flag]);
	if (action_flag == TIME_TO_EAT)
		gettimeofday(&this_philo->last_eat, NULL);
}



void	*philo_run(void *philos)
{
	t_philo_info	*this_philo;
	timeval			start_time;

	this_philo = (t_philo_info *)philos;
	gettimeofday(&this_philo->last_eat, NULL);
	gettimeofday(&start_time, NULL);
	if (this_philo->index % 2 == 0)
		usleep(200);
	while (check_die_mutex_flag(this_philo->die_mutex, this_philo->die_flag))
	{
		philo_lock_forks(this_philo->fork_left, this_philo->fork_right, start_time, this_philo->index);
		philo_action_and_print(start_time, this_philo, "is eating\n", TIME_TO_EAT);
		philo_unlock_forks(this_philo->fork_left, this_philo->fork_right);
		philo_action_and_print(start_time, this_philo, "is sleeping\n", TIME_TO_SLEEP);
		philo_action_and_print(start_time, this_philo, "is thinking\n", 0);
	}
	philo_action_and_print(start_time, this_philo, "is died\n", 0);
	return (NULL);
}

static void *philo_monitor_run(void *philos)
{
	t_philo_monitor_info	*monitor;

	monitor = calloc(ONE_MALLOC, sizeof(t_philo_monitor_info));
	philo_malloc(monitor, philos);
	philo_init(monitor);
	philo_wait_and_free(monitor);
	return (NULL);
}

void	run_thread(int *get_parse)
{
	pthread_t		philo_monitor;
	int				i;

	pthread_create(&philo_monitor, NULL, philo_monitor_run, get_parse);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
	{
		if (pthread_join(philo_monitor, NULL) == 0)
			printf("[%d monitor thread is return !! ]\n", i);
		else
			print_error(1);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/29 03:30:42 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_action_and_print(timeval start_time, t_philo_info *this_philo, char *strs, int action_flag)
{
	if (check_philo_die(this_philo, action_flag))
		return ;
	if (action_flag == TIME_TO_EAT)
		gettimeofday(&this_philo->last_eat, NULL);
	philo_print(start_time, this_philo, strs);
	if (action_flag != 0)
		ms_usleep(this_philo->get_parse[action_flag]);
}

void	*philo_run(void *philos)
{
	t_philo_info	*this_philo;
	timeval			start_time;

	this_philo = (t_philo_info *)philos;
	gettimeofday(&this_philo->last_eat, NULL);
	gettimeofday(&start_time, NULL);
	if (this_philo->index % 2 == 0)
		usleep(1000);
	while (check_philo_die(this_philo, NOTTING_ACTION) == 0)
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
	unsigned int			i;
	monitor = calloc(ONE_MALLOC, sizeof(t_philo_monitor_info));
	philo_malloc(monitor, philos);
	philo_init(monitor);
	philo_wait_and_free(monitor);
	i = 0;
	while (1)
	{
		if (check_die_mutex_flag(monitor[i % ]))
	}
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
	}
}
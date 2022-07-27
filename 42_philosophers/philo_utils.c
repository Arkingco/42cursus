/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:59:54 by kipark            #+#    #+#             */
/*   Updated: 2022/07/27 21:58:23 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ms_usleep(int ms_second)
{
	timeval	start_time;

	gettimeofday(&start_time, NULL);
	while(get_diff_time(start_time) <= ms_second)
		usleep(1000);
}

int get_diff_time(timeval start_time)
{
	timeval end_time;

	gettimeofday(&end_time, NULL);
	return	(int)(end_time.tv_sec - start_time.tv_sec) * 1000 + ((end_time.tv_usec - start_time.tv_usec) / 1000);
}

void philo_lock_forks(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right)
{
	pthread_mutex_lock(fork_left); 
	pthread_mutex_lock(fork_right);
}

void philo_unlock_forks(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right)
{
	pthread_mutex_unlock(fork_left);
	pthread_mutex_unlock(fork_right);
}
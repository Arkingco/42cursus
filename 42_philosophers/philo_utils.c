/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:59:54 by kipark            #+#    #+#             */
/*   Updated: 2022/07/29 05:18:19 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ms_usleep(int ms_second)
{
	timeval	start_time;

	gettimeofday(&start_time, NULL);
	while(get_diff_time(start_time) < ms_second)
		usleep(100);
}

int		get_diff_time(timeval start_time)
{
	timeval end_time;

	gettimeofday(&end_time, NULL);
	return	(int)(end_time.tv_sec - start_time.tv_sec) * 1000 + ((end_time.tv_usec - start_time.tv_usec) / 1000);
}

void	philo_lock_forks(t_philo_info *this_philo, timeval start_time, int philo_index)
{
	if(check_philo_die(this_philo, NOTTING_ACTION))
		return ;
	if (philo_index % 2 == 0)
	{
		pthread_mutex_lock(this_philo->fork_left);
		philo_print(start_time, philo_index, "has taken a fork \n");
		pthread_mutex_lock(this_philo->fork_right);
		philo_print(start_time, philo_index, "has taken a fork \n");
	}
	else
	{
		pthread_mutex_lock(this_philo->fork_right);
		philo_print(start_time, philo_index, "has taken a fork \n");
		pthread_mutex_lock(this_philo->fork_left);
		philo_print(start_time, philo_index, "has taken a fork \n");
	}
}

void	philo_unlock_forks(t_philo_info *this_philo)
{
	pthread_mutex_unlock(this_philo->fork_left);
	pthread_mutex_unlock(this_philo->fork_right);
}

void	philo_print(timeval start_time, int index, char *strs)
{
	printf("%04d %d %s", get_diff_time(start_time), index, strs);
}
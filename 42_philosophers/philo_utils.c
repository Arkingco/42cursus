/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:59:54 by kipark            #+#    #+#             */
/*   Updated: 2022/07/29 15:25:27 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		get_time_to_int(timeval time)
{
	return (int)(time.tv_sec * 1000) + (time.tv_usec / 1000);
}

void	ms_usleep(int ms_second)
{
	timeval	start_time;
	int		start_time_to_int;

	start_time_to_int = get_time_to_int(start_time);
	gettimeofday(&start_time, NULL);
	while(get_diff_time(start_time_to_int) <= ms_second)
		usleep(100);
}

int		get_diff_time(int start_time)
{
	timeval end_time;
	int		end_time_int;

	gettimeofday(&end_time, NULL);
	end_time_int = (end_time.tv_sec * 1000) + (end_time.tv_usec / 1000);
	return	end_time_int - start_time;
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
	if (this_philo->index % 2 == 0)
	{
		pthread_mutex_unlock(this_philo->fork_left);
		pthread_mutex_unlock(this_philo->fork_right);
	}
	else
	{
		pthread_mutex_unlock(this_philo->fork_left);
		pthread_mutex_unlock(this_philo->fork_right);
	}
	
}

void	philo_print(timeval start_time, int index, char *strs)
{
	printf("%04d %d %s", get_diff_time(get_time_to_int(start_time)), index, strs);
}
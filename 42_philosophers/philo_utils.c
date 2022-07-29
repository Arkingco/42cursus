/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:59:54 by kipark            #+#    #+#             */
/*   Updated: 2022/07/29 16:36:55 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ms_usleep(t_philo_info *this_philo, int ms_second)
{
	timeval	start_time;

	gettimeofday(&start_time, NULL);
	while(get_diff_time(start_time) < ms_second)
	{
		if (check_philo_die(this_philo, NOTTING_ACTION))
			break ;
		usleep(100);
	}
}

long	get_diff_time(timeval start_time)
{
	timeval end_time;
	long	end_time_int;
	long	start_time_int;

	gettimeofday(&end_time, NULL);
	end_time_int = (long)((end_time.tv_sec * 1000) + (end_time.tv_usec / 1000));
	start_time_int = (long)((start_time.tv_sec * 1000) + (start_time.tv_usec / 1000));
	return	(end_time_int - start_time_int);
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
	printf("%04ld %d %s", get_diff_time(start_time), index, strs);
}
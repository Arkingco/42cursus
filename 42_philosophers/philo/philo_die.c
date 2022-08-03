/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:11:57 by baggiseon         #+#    #+#             */
/*   Updated: 2022/08/03 12:54:25 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag)
{
	pthread_mutex_lock(die_mutex);
	*die_flag = 1;
	pthread_mutex_unlock(die_mutex);
}

void	set_last_eat(pthread_mutex_t *eat_mutex, t_timeval *last_eat)
{
	pthread_mutex_lock(eat_mutex);
	gettimeofday(last_eat, NULL);
	pthread_mutex_unlock(eat_mutex);
}

int	check_philo_last_eat(t_philo_monitor_info *monitor, t_timeval *last_eat, int time_to_die)
{
	pthread_mutex_lock(monitor->eat_mutex);
	if (get_diff_time(*last_eat) >= time_to_die)
	{
		set_die_mutex_flag(monitor->die_mutex, monitor->die_flag);
		return (1);
	}
	pthread_mutex_unlock(monitor->eat_mutex);
	return (0);
}

int	check_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag)
{
	pthread_mutex_lock(die_mutex);
	if (*die_flag == 1)
	{
		pthread_mutex_unlock(die_mutex);
		return (1);
	}
	pthread_mutex_unlock(die_mutex);
	return (0);
}

int	check_philo_die(t_philo_info *this_philo)
{
	if (check_die_mutex_flag(this_philo->die_mutex, this_philo->die_flag))
		return (1);
	return (0);
}


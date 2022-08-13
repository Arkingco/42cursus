/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex_get_set.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:01:33 by kipark            #+#    #+#             */
/*   Updated: 2022/08/10 19:54:31 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_eat(pthread_mutex_t *eat_mutex, t_timeval *last_eat)
{
	pthread_mutex_lock(eat_mutex);
	gettimeofday(last_eat, NULL);
	pthread_mutex_unlock(eat_mutex);
}

int	check_philo_last_eat(t_philo_monitor_info *monitor, t_timeval *last_eat, \
																int time_to_die)
{
	pthread_mutex_lock(monitor->eat_mutex);
	if (get_diff_time(*last_eat) >= time_to_die)
		return (1);
	pthread_mutex_unlock(monitor->eat_mutex);
	return (0);
}

void	up_count_all_eat_mutex_flag(pthread_mutex_t *all_eat_mutex, \
															int *all_eat_count)
{
	pthread_mutex_lock(all_eat_mutex);
	*all_eat_count = *all_eat_count + 1;
	pthread_mutex_unlock(all_eat_mutex);
}

int	check_count_all_eat_mutex_flag(pthread_mutex_t *all_eat_mutex, \
									int *all_eat_count, int all_philo_number)
{
	pthread_mutex_lock(all_eat_mutex);
	if (all_philo_number - 1 == *all_eat_count)
		return (1);
	pthread_mutex_unlock(all_eat_mutex);
	return (0);
}

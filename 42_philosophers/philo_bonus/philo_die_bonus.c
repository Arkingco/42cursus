/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:11:57 by baggiseon         #+#    #+#             */
/*   Updated: 2022/08/07 14:51:01 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_die_sem_flag(sem_t *die_sem, int *die_flag)
{
	sem_wait(die_sem);
	*die_flag = 1;
	sem_post(die_sem);
}

void	set_last_eat(sem_t *eat_sem, t_timeval *last_eat)
{
	sem_wait(eat_sem);
	gettimeofday(last_eat, NULL);
	sem_post(eat_sem);
}

int	check_philo_last_eat(t_philo_monitor_info *monitor, \
										t_timeval *last_eat, int time_to_die)
{
	sem_wait(monitor->eat_sem);
	if (get_diff_time(*last_eat) >= time_to_die)
		return (1);
	sem_post(monitor->eat_sem);
	return (0);
}

int	check_die_sem_flag(sem_t *die_sem, int *die_flag)
{
	sem_wait(die_sem);
	if (*die_flag == 1)
	{
		sem_post(die_sem);
		return (1);
	}
	sem_post(die_sem);
	return (0);
}

int	check_philo_die(t_philo_info *this_philo)
{
	if (check_die_sem_flag(this_philo->die_sem, this_philo->die_flag))
		return (1);
	return (0);
}

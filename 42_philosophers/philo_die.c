/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:11:57 by baggiseon         #+#    #+#             */
/*   Updated: 2022/07/29 03:26:50 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag)
{
	printf("1\n");
	pthread_mutex_lock(die_mutex);
	printf("2\n");

	*die_flag = 1;
	pthread_mutex_unlock(die_mutex);
	printf("3\n");

}

int		check_die_mutex_flag(pthread_mutex_t *die_mutex, int *die_flag)
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

int		check_philo_die(t_philo_info *this_philo, int action_flag)
{
    if (check_die_mutex_flag(this_philo->die_mutex, &this_philo->die_flag))
		return (1);
	if (get_diff_time(this_philo->last_eat) >= this_philo->get_parse[TIME_TO_DIE])
	{
		printf("this_philo is dead %d : action flag\n", action_flag);
		set_die_mutex_flag(this_philo->die_mutex, &this_philo->die_flag);
		if (action_flag == TIME_TO_EAT)
			philo_unlock_forks(this_philo->fork_left, this_philo->fork_right);
		return (1);
	}
	return (0);
}
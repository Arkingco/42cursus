/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:11:57 by baggiseon         #+#    #+#             */
/*   Updated: 2022/07/29 16:39:30 by kipark           ###   ########.fr       */
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
		set_die_mutex_flag(this_philo->die_mutex, &this_philo->die_flag);
		if (action_flag == TIME_TO_EAT)
			philo_unlock_forks(this_philo);
		philo_print(this_philo->start_time, this_philo->index, "is died\n");
		return (1);
	}
	return (0);
}
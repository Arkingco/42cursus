/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:59:54 by kipark            #+#    #+#             */
/*   Updated: 2022/08/07 14:57:53 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ms_usleep(int ms_second)
{
	t_timeval	start_time;

	gettimeofday(&start_time, NULL);
	while (get_diff_time(start_time) < ms_second)
		usleep(300);
}

long	get_diff_time(t_timeval start_time)
{
	t_timeval	end_time;
	long		end_time_int;
	long		start_time_int;

	gettimeofday(&end_time, NULL);
	end_time_int = \
			(long)((end_time.tv_sec * 1000) + (end_time.tv_usec / 1000));
	start_time_int = \
			(long)((start_time.tv_sec * 1000) + (start_time.tv_usec / 1000));
	return (end_time_int - start_time_int);
}

void	philo_lock_forks(t_philo_info *this_philo)
{
	if (check_philo_die(this_philo))
		return ;
	sem_wait(this_philo->forks);
	philo_print(this_philo, "has taken a fork \n");
	sem_wait(this_philo->forks);
	philo_print(this_philo, "has taken a fork \n");
}

void	philo_unlock_forks(t_philo_info *this_philo)
{
	sem_post(this_philo->forks);
	sem_post(this_philo->forks);
}

void	philo_print(t_philo_info *this_philo, char *strs)
{
	if (check_philo_die(this_philo))
		return ;
	printf("%ld %d %s", \
				get_diff_time(this_philo->start_time), this_philo->index, strs);
}

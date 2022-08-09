/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:50:36 by kipark            #+#    #+#             */
/*   Updated: 2022/08/09 14:30:12 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_malloc(t_philo_monitor_info *monitor, void *philos)
{
	monitor->get_parse = (int *)philos;
	monitor->all_philo_number = monitor->get_parse[ALL_PHILO_NUMBER];
	monitor->philosophers_thread = \
		ft_calloc(monitor->all_philo_number, sizeof(pthread_t));
	monitor->philosophers = \
		ft_calloc(monitor->all_philo_number, sizeof(t_philo_info));
	monitor->forks = \
		ft_calloc(monitor->all_philo_number, sizeof(pthread_mutex_t));
	monitor->die_mutex = ft_calloc(ONE_MALLOC, sizeof(pthread_mutex_t));
	monitor->die_flag = ft_calloc(ONE_MALLOC, sizeof(int));
	monitor->eat_mutex = ft_calloc(ONE_MALLOC, sizeof(pthread_mutex_t));
	monitor->all_eat_count = ft_calloc(ONE_MALLOC, sizeof(int));
	monitor->all_eat_mutex = ft_calloc(ONE_MALLOC, sizeof(pthread_mutex_t));
}

static void	philo_info_init(int philo_index, \
						t_philo_info *philo_info, t_philo_monitor_info *monitor)
{
	philo_info->index = philo_index + 1;
	philo_info->fork_left = &monitor->forks[philo_index];
	philo_info->fork_right = \
				&monitor->forks[(philo_index + 1) % monitor->all_philo_number];
	philo_info->die_flag = monitor->die_flag;
	philo_info->die_mutex = monitor->die_mutex;
	philo_info->eat_mutex = monitor->eat_mutex;
	philo_info->start_time = monitor->start_time;
	philo_info->get_parse = monitor->get_parse;
	philo_info->all_eat_count = monitor->all_eat_count;
	philo_info->all_eat_mutex = monitor->all_eat_mutex;
	philo_info->eat_count = monitor->get_parse[MUST_EAT_NUMBER];
}

void	philo_init(t_philo_monitor_info *monitor)
{
	int	i;

	i = -1;
	while (++i < monitor->all_philo_number)
		pthread_mutex_init(&monitor->forks[i], NULL);
	pthread_mutex_init(monitor->die_mutex, NULL);
	pthread_mutex_init(monitor->eat_mutex, NULL);
	pthread_mutex_init(monitor->all_eat_mutex, NULL);
	gettimeofday(&monitor->start_time, NULL);
	i = -1;
	while (++i < monitor->all_philo_number)
		philo_info_init(i, &monitor->philosophers[i], monitor);
	i = -1;
	while (++i < monitor->all_philo_number)
		pthread_create(&monitor->philosophers_thread[i], \
		NULL, \
		philo_run, \
		&monitor->philosophers[i]);
	usleep(1000);
}

void	philo_wait_and_free(t_philo_monitor_info *monitor, \
														pthread_t *all_eat_wait)
{
	int	i;

	i = -1;
	while (++i < monitor->all_philo_number)
		if (pthread_join(monitor->philosophers_thread[i], NULL) != 0)
			print_error(1);
	i = -1;
	while (++i < monitor->all_philo_number)
		pthread_mutex_destroy(&monitor->forks[i]);
	pthread_join(*all_eat_wait, NULL);
	pthread_mutex_destroy(monitor->die_mutex);
	pthread_mutex_destroy(monitor->eat_mutex);
	pthread_mutex_destroy(monitor->all_eat_mutex);
	free(monitor->get_parse);
	free(monitor->philosophers_thread);
	free(monitor->philosophers);
	free(monitor->forks);
	free(monitor->die_mutex);
	free(monitor->die_flag);
	free(monitor->eat_mutex);
	free(monitor->all_eat_count);
	free(monitor->all_eat_mutex);
	free(monitor);
}

void	philo_all_mutex_unlock(t_philo_info *philo)
{
	t_philo_info	*this_philo;

	this_philo = philo;
	pthread_mutex_unlock(this_philo->die_mutex);
	pthread_mutex_unlock(this_philo->eat_mutex);
	pthread_mutex_unlock(this_philo->all_eat_mutex);
	pthread_mutex_unlock(this_philo->fork_left);
	pthread_mutex_unlock(this_philo->fork_right);
}

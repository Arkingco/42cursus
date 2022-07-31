/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:50:36 by kipark            #+#    #+#             */
/*   Updated: 2022/07/31 19:34:04 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_malloc(t_philo_monitor_info *monitor, void *philos)
{
	monitor->get_parse = (int *)philos;
	monitor->philosophers_thread = \
		ft_calloc(monitor->get_parse[ALL_PHILO_NUMBER], sizeof(pthread_t));
	monitor->philosophers = \
		ft_calloc(monitor->get_parse[ALL_PHILO_NUMBER], sizeof(t_philo_info));
	monitor->forks = \
		ft_calloc(monitor->get_parse[ALL_PHILO_NUMBER], sizeof(pthread_mutex_t));
	monitor->die_mutex = ft_calloc(ONE_MALLOC, sizeof(pthread_mutex_t));
}


static void	philo_info_init(int philo_index, t_philo_info *philo_info, t_philo_monitor_info *monitor)
{
	philo_info->index = philo_index + 1;
	philo_info->fork_left = &monitor->forks[philo_index];
	philo_info->fork_right = &monitor->forks[(philo_index + 1) % monitor->get_parse[ALL_PHILO_NUMBER]];
	philo_info->get_parse = monitor->get_parse;
	philo_info->die_flag = 0;
	philo_info->die_mutex = monitor->die_mutex;
	philo_info->start_time = monitor->start_time;
	philo_info->eat_count = monitor->get_parse[MUST_EAT_NUMBER];
}

void philo_init(t_philo_monitor_info *monitor)
{
	int i;

	i = -1;
	while (++i < monitor->get_parse[ALL_PHILO_NUMBER])
		pthread_mutex_init(&monitor->forks[i], NULL);
	pthread_mutex_init(monitor->die_mutex, NULL);
	gettimeofday(&monitor->start_time, NULL);
	i = -1;
	while (++i < monitor->get_parse[ALL_PHILO_NUMBER])
		philo_info_init(i, &monitor->philosophers[i], monitor);
	i = -1;
	while (++i < monitor->get_parse[ALL_PHILO_NUMBER])
		pthread_create(&monitor->philosophers_thread[i], NULL, philo_run, &monitor->philosophers[i]);
}

void philo_wait_and_free(t_philo_monitor_info *monitor)
{
	int i;

	i = -1;
	while (++i < monitor->get_parse[ALL_PHILO_NUMBER])
		if(pthread_join(monitor->philosophers_thread[i], NULL) != 0)
			print_error(1);
	i = -1;
	while (++i < monitor->get_parse[ALL_PHILO_NUMBER])
		pthread_mutex_destroy(&monitor->forks[i]);
	free(monitor->get_parse);
	free(monitor->philosophers_thread);
	free(monitor->philosophers);
	free(monitor->forks);
	free(monitor->die_mutex);
	free(monitor);
}

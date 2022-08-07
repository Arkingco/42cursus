/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:50:36 by kipark            #+#    #+#             */
/*   Updated: 2022/08/07 14:51:09 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_malloc(t_philo_main_monitor_info *main_monitor, \
						t_philo_monitor_info *monitor, int index, void *philos)
{
	monitor->get_parse = (int *)philos;
	monitor->all_philo_number = monitor->get_parse[ALL_PHILO_NUMBER];
	monitor->philosophers_thread = \
		ft_calloc(ONE_MALLOC, sizeof(pthread_t));
	monitor->philosophers = \
		ft_calloc(monitor->all_philo_number, sizeof(t_philo_info));
	monitor->forks = main_monitor->forks;
	monitor->die_sem = main_monitor->die_sem;
	monitor->eat_sem = main_monitor->eat_sem;
	monitor->all_die_sem = main_monitor->all_die_sem;
	monitor->all_eat_sem = main_monitor->all_eat_sem;
	monitor->die_flag = ft_calloc(ONE_MALLOC, sizeof(int));
	*monitor->die_flag = 0;
	monitor->index = index;
}

static void	philo_info_init(int philo_index, \
						t_philo_info *philo_info, t_philo_monitor_info *monitor)
{
	philo_info->index = philo_index + 1;
	philo_info->forks = monitor->forks;
	philo_info->get_parse = monitor->get_parse;
	philo_info->die_flag = monitor->die_flag;
	philo_info->die_sem = monitor->die_sem;
	philo_info->eat_sem = monitor->eat_sem;
	philo_info->all_eat_sem = monitor->all_eat_sem;
	philo_info->start_time = monitor->start_time;
	philo_info->eat_count = monitor->get_parse[MUST_EAT_NUMBER];
}

void	philo_init(t_philo_main_monitor_info *main_monitor, \
									t_philo_monitor_info *monitor, int index)
{
	int	i;

	monitor->start_time = main_monitor->start_time;
	i = -1;
	while (++i < monitor->all_philo_number)
		philo_info_init(index, &monitor->philosophers[i], monitor);
	i = -1;
	while (++i < monitor->all_philo_number)
		pthread_create(&monitor->philosophers_thread[i], \
		NULL, \
		philo_run, \
		&monitor->philosophers[i]);
}

void	philo_wait_and_free(t_philo_monitor_info *monitor)
{
	int	i;

	i = -1;
	while (++i < monitor->all_philo_number)
		if (pthread_join(monitor->philosophers_thread[i], NULL) != 0)
			print_error(1);
	i = -1;
	free(monitor->get_parse);
	free(monitor->philosophers_thread);
	free(monitor->philosophers);
	free(monitor->die_flag);
	free(monitor);
}

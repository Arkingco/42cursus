/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:59:54 by kipark            #+#    #+#             */
/*   Updated: 2022/08/11 12:44:55 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_parse_set_to_fork(int *get_parse)
{
	get_parse[ALL_PHILO_NUMBER] = 1;
}

void	main_monitor_info_init(t_philo_main_monitor_info *main_monitor, \
																int *get_parse)
{
	main_monitor->all_philo_number = get_parse[ALL_PHILO_NUMBER];
	main_monitor->forks = make_semaphore("forks", get_parse[ALL_PHILO_NUMBER]);
	main_monitor->die_sem = make_semaphore("die_sem", 1);
	main_monitor->eat_sem = make_semaphore("eat_sem", 1);
	main_monitor->all_die_sem = make_semaphore("all_die_sem", 0);
	main_monitor->all_eat_sem = make_semaphore("all_eat_sem", 0);
	gettimeofday(&main_monitor->start_time, NULL);
}

void	unlinks_sem(t_philo_main_monitor_info *main_monitor)
{
	t_philo_main_monitor_info	*monitor;

	monitor = main_monitor;
	sem_unlink("forks");
	sem_unlink("die_sem");
	sem_unlink("eat_sem");
	sem_unlink("all_die_sem");
	sem_unlink("all_eat_sem");
}

void	kill_philos(t_philo_main_monitor_info *main_monitor, \
					pthread_t *wait_all_eat, int all_philo_number, int *pid)
{
	int	i;

	sem_wait(main_monitor->all_die_sem);
	sem_wait(main_monitor->die_sem);
	usleep(10000);
	unlinks_sem(main_monitor);
	i = -1;
	while (++i < all_philo_number)
		sem_post(main_monitor->all_eat_sem);
	pthread_join(*wait_all_eat, NULL);
	i = -1;
	while (++i < all_philo_number)
		kill(pid[i], SIGKILL);
	return ;
}

sem_t	*make_semaphore(char *str, int count)
{
	sem_t	*sem;

	sem = sem_open(str, O_CREAT | O_EXCL, 0644, count);
	if (sem == (sem_t *)-1)
	{
		sem_unlink(str);
		sem = sem_open(str, O_CREAT | O_EXCL, 0644, count);
	}
	return (sem);
}

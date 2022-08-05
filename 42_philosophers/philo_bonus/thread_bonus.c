/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/08/05 19:27:04 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_action_and_print( \
	t_philo_info *this_philo, char *strs, int action_flag)
{
	if (check_philo_die(this_philo))
		return ;
	if (action_flag == TIME_TO_EAT)
		set_last_eat(this_philo->eat_sem, &this_philo->last_eat);
	philo_print(this_philo, strs);
	if (action_flag != 0)
		ms_usleep(this_philo->get_parse[action_flag]);
}

void	*philo_run(void *philos)
{
	t_philo_info	*this_philo;
	int				eat_count;

	this_philo = (t_philo_info *)philos;
	eat_count = 0;
	set_last_eat(this_philo->eat_sem, &this_philo->last_eat);
	while (check_philo_die(this_philo) == 0 && \
			(eat_count < this_philo->eat_count || this_philo->eat_count == -1))
	{
		philo_lock_forks(this_philo);
		philo_action_and_print(this_philo, "is eating\n", TIME_TO_EAT);
		philo_unlock_forks(this_philo);
		philo_action_and_print(this_philo, "is sleeping\n", TIME_TO_SLEEP);
		philo_action_and_print(this_philo, "is thinking\n", 0);
		usleep(300);
		eat_count++;
	}
	return (NULL);
}

void	philo_process_run(int index, int *get_parse, t_philo_main_monitor_info * main_monitor)
{
	t_philo_monitor_info	*monitor;
	unsigned int			i;

	
	monitor = calloc(ONE_MALLOC, sizeof(t_philo_monitor_info));
	philo_malloc(main_monitor, monitor, index, get_parse);
	philo_init(main_monitor, monitor, index);
	ms_usleep(monitor->get_parse[TIME_TO_EAT] * 0.1);
	i = -1;
	while (1)
		if (check_philo_last_eat(monitor, \
			&monitor->philosophers[++i % monitor->all_philo_number].last_eat, \
			monitor->get_parse[TIME_TO_DIE]))
	{
		philo_print(&monitor->philosophers[i % monitor->all_philo_number], "is died\n");
		sem_post(monitor->all_die_sem);
		break;
	}
	philo_wait_and_free(monitor);
	exit(1);
}

void get_parse_set_to_fork(int *get_parse)
{
	get_parse[ALL_PHILO_NUMBER] = 1;
}

void	main_monitor_info_init(t_philo_main_monitor_info *main_monitor, \
																int *get_parse)
{
	main_monitor->forks = make_semaphore("forks", get_parse[ALL_PHILO_NUMBER]);
	main_monitor->die_sem = make_semaphore("die_sem", 1);
	main_monitor->eat_sem = make_semaphore("eat_sem", 1);
	main_monitor->all_die_sem = make_semaphore("all_die_sem", 0);
	main_monitor->all_eat_sem = make_semaphore("all_eat_sem", 0);
	gettimeofday(&main_monitor->start_time, NULL);
}

void	run_thread(int *get_parse)
{
	int		pid[200];
	int		i;
	int		all_philo_number;
	pid_t	wait_id;
	t_philo_main_monitor_info	main_monitor;

	main_monitor_info_init(&main_monitor, get_parse);
	i = -1;
	all_philo_number = get_parse[ALL_PHILO_NUMBER];
	get_parse_set_to_fork(get_parse);
	while (++i < all_philo_number)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			break ;
		if (pid[i] == 0)
		{
			philo_process_run(i, get_parse, &main_monitor);
		}
	}
	i = -1;
	sem_wait(main_monitor.all_die_sem);
	sem_wait(main_monitor.die_sem);
	while (++i < get_parse[ALL_PHILO_NUMBER])
		kill(pid[i], SIGKILL);
	while (++i < get_parse[ALL_PHILO_NUMBER])
		wait_id = wait(&pid[i]);
}

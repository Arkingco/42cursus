/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/08/09 19:33:05 by kipark           ###   ########.fr       */
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
				this_philo->eat_count != 0)
	{
		philo_lock_forks(this_philo);
		philo_action_and_print(this_philo, "is eating\n", TIME_TO_EAT);
		philo_unlock_forks(this_philo);
		eat_count++;
		if (eat_count == this_philo->eat_count)
			sem_post(this_philo->all_eat_sem);
		philo_action_and_print(this_philo, "is sleeping\n", TIME_TO_SLEEP);
		philo_action_and_print(this_philo, "is thinking\n", 0);
	}
	sem_post(this_philo->all_eat_sem);
	exit(1);
	return (NULL);
}

void	philo_process_run(int index, int *get_parse, \
									t_philo_main_monitor_info *main_monitor)
{
	t_philo_monitor_info	*monitor;
	unsigned int			i;

	monitor = ft_calloc(ONE_MALLOC, sizeof(t_philo_monitor_info));
	philo_malloc(main_monitor, monitor, index, get_parse);
	philo_init(main_monitor, monitor, index);
	usleep(monitor->get_parse[TIME_TO_EAT] * 0.8);
	i = -1;
	while (1)
	{
		if (check_philo_last_eat(monitor, \
			&monitor->philosophers[++i % monitor->all_philo_number].last_eat, \
			monitor->get_parse[TIME_TO_DIE]))
		{
			philo_print(&monitor->philosophers[i % monitor->all_philo_number], \
																"is died\n");
			sem_post(monitor->all_die_sem);
		}
	}
	return ;
}

void	*wait_all_philo_eat(void *arg)
{
	int							i;
	t_philo_main_monitor_info	*main_monitor;

	main_monitor = (t_philo_main_monitor_info *)arg;
	i = -1;
	while (++i < main_monitor->all_philo_number)
		sem_wait(main_monitor->all_eat_sem);
	sem_post(main_monitor->all_die_sem);
	return (NULL);
}

void	run_thread(int *get_parse)
{
	int							pid[200];
	int							i;
	int							all_philo_number;
	pthread_t					wait_all_eat;
	t_philo_main_monitor_info	main_monitor;

	main_monitor_info_init(&main_monitor, get_parse);
	all_philo_number = get_parse[ALL_PHILO_NUMBER];
	if (all_philo_number > 200)
		print_error(1);
	get_parse_set_to_fork(get_parse);
	i = -1;
	while (++i < all_philo_number)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			print_error(1);
		if (pid[i] == 0)
			philo_process_run(i, get_parse, &main_monitor);
	}
	pthread_create(&wait_all_eat, NULL, wait_all_philo_eat, &main_monitor);
	kill_philos(&main_monitor, &wait_all_eat, all_philo_number, pid);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/08/04 21:07:51 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	philo_action_and_print( \
	t_philo_info *this_philo, char *strs, int action_flag)
{
	if (check_philo_die(this_philo))
		return ;
	if (action_flag == TIME_TO_EAT)
		gettimeofday(&this_philo->last_eat, NULL);
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
	// set_last_eat(this_philo->eat_mutex, &this_philo->last_eat);
	if (this_philo->index % 2 == 0)
		ms_usleep(this_philo->get_parse[TIME_TO_EAT] * 0.1);
	while (1)
	{
		philo_lock_forks(this_philo);
		philo_action_and_print(this_philo, "is eating\n", TIME_TO_EAT);
		philo_unlock_forks(this_philo);
		philo_action_and_print(this_philo, "is sleeping\n", TIME_TO_SLEEP);
		philo_action_and_print(this_philo, "is thinking\n", 0);
		usleep(300);
		eat_count++;
	}
	printf("\n end \n");
	return (NULL);
}

void	philo_process_run(int index, int *get_parse, t_philo_main_monitor_info * main_monitor)
{
	t_philo_monitor_info	*monitor;
	unsigned int			i;

	
	monitor = calloc(ONE_MALLOC, sizeof(t_philo_monitor_info));
	philo_malloc(main_monitor, monitor, index, get_parse);
	philo_init(monitor, index);
	ms_usleep(monitor->get_parse[TIME_TO_EAT] * 0.1);
	i = -1;
	while (1)
		if (check_philo_last_eat(
			&monitor->philosophers[++i % monitor->all_philo_number].last_eat, \
			monitor->get_parse[TIME_TO_DIE]))
	{
		philo_print(&monitor->philosophers[i % monitor->all_philo_number], "is died\n");
		set_die_sem_flag(monitor->die_sem, monitor->die_flag);
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
	main_monitor->die_sem = make_semaphore("die_sem", 200);
	main_monitor->all_eat_sem = make_semaphore("all_eat_sem", 0);
}

void	run_thread(int *get_parse)
{
	int		pid;
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
		pid = fork();
		if (pid == -1)
			break ;
		if (pid == 0)
		{
			philo_process_run(i, get_parse, &main_monitor);
		}
	}
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		wait_id = wait(&pid);
	// for(int i=0; i<1000; ++i)
	// {
	// 	wait_pid = wait(0);
	// }
	// ret = sem_close(sem); // 세마포어 종료 및 할당한 자원 해제
	// printf("sem_close: %d\n", ret);
	// ret = sem_unlink("test_sem"); // 세마포어 객체 해제
	// printf("sem_unlink: %d\n", ret);

}

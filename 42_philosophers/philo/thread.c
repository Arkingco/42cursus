/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/08/08 15:26:19 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_action_and_print( \
	t_philo_info *this_philo, char *strs, int action_flag)
{
	if (check_philo_die(this_philo))
		return ;
	if (action_flag == TIME_TO_EAT)
		set_last_eat(this_philo->eat_mutex, &this_philo->last_eat);
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
	set_last_eat(this_philo->eat_mutex, &this_philo->last_eat);
	if (this_philo->index % 2 == 0)
		ms_usleep(this_philo->get_parse[TIME_TO_EAT] * 0.1);
	while (check_philo_die(this_philo) == 0)
	{
		philo_lock_forks(this_philo, this_philo->index);
		philo_action_and_print(this_philo, "is eating\n", TIME_TO_EAT);
		philo_unlock_forks(this_philo);
		eat_count++;
		if (eat_count == this_philo->eat_count)
			up_count_all_eat_mutex_flag(this_philo->all_eat_mutex, \
													this_philo->all_eat_count);
		philo_action_and_print(this_philo, "is sleeping\n", TIME_TO_SLEEP);
		philo_action_and_print(this_philo, "is thinking\n", 0);
		usleep(300);
	}
	return (NULL);
}

void	*philo_all_eat_wait(void *philos)
{
	t_philo_monitor_info	*this_monitor;

	this_monitor = (t_philo_monitor_info *)philos;
	while (1)
	{
		if (check_count_all_eat_mutex_flag(this_monitor->all_eat_mutex, \
			this_monitor->all_eat_count, this_monitor->all_philo_number) || \
			check_philo_die(&this_monitor->philosophers[0]))
			break ;
	}
	set_die_mutex_flag(this_monitor->die_mutex, this_monitor->die_flag);
	return (NULL);
}

static void	*philo_monitor_run(void *philos)
{
	t_philo_monitor_info	*monitor;
	pthread_t				all_eat_wait;
	unsigned int			i;

	monitor = calloc(ONE_MALLOC, sizeof(t_philo_monitor_info));
	philo_malloc(monitor, philos);
	philo_init(monitor);
	usleep(1000);
	pthread_create(&all_eat_wait, NULL, philo_all_eat_wait, monitor);
	i = -1;
	while (1)
	{
		if (check_philo_last_eat(monitor, \
			&monitor->philosophers[++i % monitor->all_philo_number].last_eat, \
			monitor->get_parse[TIME_TO_DIE]))
		{
			philo_print(&monitor->philosophers[i % monitor->all_philo_number], \
																"is died\n");
			set_die_mutex_flag(monitor->die_mutex, monitor->die_flag);
			break ;
		}
	}
	philo_wait_and_free(monitor, &all_eat_wait);
	return (NULL);
}

void	run_thread(int *get_parse)
{
	pthread_t		philo_monitor;
	int				i;

	pthread_create(&philo_monitor, NULL, philo_monitor_run, get_parse);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		if (pthread_join(philo_monitor, NULL) == 0)
			break ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/29 18:06:38 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_action_and_print(timeval start_time, t_philo_info *this_philo, char *strs, int action_flag)
{
	if (check_philo_die(this_philo, action_flag))
		return ;
	if (action_flag == TIME_TO_EAT)
		gettimeofday(&this_philo->last_eat, NULL);
	philo_print(start_time, this_philo->index, strs);
	if (action_flag != 0)
		ms_usleep(this_philo, this_philo->get_parse[action_flag]);
}

void	*philo_run(void *philos)
{
	t_philo_info	*this_philo;
	timeval			start_time;
	int				eat_count;

	this_philo = (t_philo_info *)philos;
	start_time = this_philo->start_time;
	eat_count = 0;
	gettimeofday(&this_philo->last_eat, NULL);
	if (this_philo->index % 2 == 0)
		usleep(300);
	while (check_philo_die(this_philo, NOTTING_ACTION) == 0&& \
			(eat_count < this_philo->eat_count || this_philo->eat_count == -1))
	{ 
		philo_lock_forks(this_philo, start_time, this_philo->index);
		philo_action_and_print(start_time, this_philo, "is eating\n", TIME_TO_EAT);
		philo_unlock_forks(this_philo);
		philo_action_and_print(start_time, this_philo, "is sleeping\n", TIME_TO_SLEEP);
		philo_action_and_print(start_time, this_philo, "is thinking\n", 0);
		usleep(300);
		eat_count++;
	}
	if (eat_count >= this_philo->eat_count)
		set_die_mutex_flag(this_philo->die_mutex, &this_philo->die_flag);
	return (NULL);
}

static void *philo_monitor_run(void *philos)
{
	t_philo_monitor_info	*monitor;
	unsigned int			i;
	monitor = calloc(ONE_MALLOC, sizeof(t_philo_monitor_info));
	philo_malloc(monitor, philos);
	philo_init(monitor);
	i = -1;
	while (1)
		if (check_die_mutex_flag(monitor->die_mutex, &monitor->philosophers[++i % monitor->get_parse[ALL_PHILO_NUMBER]].die_flag))
			break;
	i = -1;
	while(++i < (unsigned int)monitor->get_parse[ALL_PHILO_NUMBER])
		set_die_mutex_flag(monitor->die_mutex, &monitor->philosophers[i % monitor->get_parse[ALL_PHILO_NUMBER]].die_flag);
	philo_wait_and_free(monitor);
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
			break;
}
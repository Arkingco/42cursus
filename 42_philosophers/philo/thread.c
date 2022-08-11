/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/08/11 12:12:34 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_action_and_print( \
	t_philo_info *this_philo, char *strs, int action_flag)
{
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
	if (this_philo->index % 2 == 0)
		ms_usleep(this_philo->get_parse[TIME_TO_EAT] * 0.1);
	while (check_philo_die(this_philo) == 0 && \
				this_philo->eat_count != 0)
	{
		philo_lock_forks(this_philo);
		philo_action_and_print(this_philo, "is eating\n", TIME_TO_EAT);
		philo_unlock_forks(this_philo);
		eat_count++;
		if (eat_count == this_philo->eat_count)
			up_count_all_eat_mutex_flag(this_philo->all_eat_mutex, \
													this_philo->all_eat_count);
		philo_action_and_print(this_philo, "is sleeping\n", TIME_TO_SLEEP);
		philo_action_and_print(this_philo, "is thinking\n", 0);
	}
	philo_all_mutex_unlock(this_philo);
	return (NULL);
}

static void	*philo_monitor_run(void *parse)
{
	t_philo_monitor_info	*monitor;
	unsigned int			i;

	monitor = ft_calloc(ONE_MALLOC, sizeof(t_philo_monitor_info));
	philo_monitor_malloc(monitor, parse);
	philo_init(monitor);
	i = -1;
	while (1)
	{
		if (check_philo_last_eat(monitor, \
			&monitor->philosophers[++i % monitor->all_philo_number].last_eat, \
			monitor->get_parse[TIME_TO_DIE]) || \
			check_count_all_eat_mutex_flag(monitor->all_eat_mutex, \
			monitor->all_eat_count, monitor->all_philo_number))
		{
			philo_print(&monitor->philosophers[i % monitor->all_philo_number], \
																"is died\n");
			pthread_mutex_lock(monitor->print_mutex);
			set_die_mutex_flag(monitor->die_mutex, monitor->die_flag);
			break ;
		}
	}
	philo_wait_and_free(monitor);
	return (NULL);
}

void	run_thread(int *get_parse)
{
	pthread_t		philo_monitor;
	int				i;

	if (pthread_create(&philo_monitor, NULL, philo_monitor_run, get_parse))
		if (print_error(1))
			return ;
	i = -1;
	if (pthread_join(philo_monitor, NULL) != 0)
		return ;
}

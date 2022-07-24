/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/24 20:32:29 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init(int philo_index, int *get_parse, t_philo_info *philo_info, pthread_mutex_t *forks)
{
	philo_info->index = philo_index;
	philo_info->fork_left = &forks[philo_index];
	philo_info->fork_right = &forks[(philo_index + 1) % get_parse[ALL_PHILO_NUMBER]];
	philo_info->get_parse = get_parse;
}

static void philo_lock_forks(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right)
{
	pthread_mutex_lock(fork_left);
	pthread_mutex_lock(fork_right);
}

static void philo_unlock_forks(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right)
{
	pthread_mutex_unlock(fork_left);
	pthread_mutex_unlock(fork_right);
}

static int get_diff_time(timeval start_time)
{
	timeval end_time;

	gettimeofday(&end_time, NULL);
	return	(int)(end_time.tv_sec - start_time.tv_sec) * 1000 + ((end_time.tv_usec - start_time.tv_usec) / 1000);
}

void philo_action_and_print(timeval start_time, int philo_index, char *strs, int ms_sleep_time)
{
	printf("%04d %d %s", get_diff_time(start_time), philo_index, strs);
	if(ms_sleep_time != 0)
		ms_usleep(ms_sleep_time);
}

static void	*philo_run(void *philos)
{
	t_philo_info	*this_philo;
	timeval			start_time;

	this_philo = (t_philo_info *)philos;
	gettimeofday(&start_time, NULL);
	if (this_philo->index % 2 == 0)
		usleep(1000);
	//----------------- start --------------------------------------//
	while (this_philo->get_parse[TIME_TO_DIE] > get_diff_time(start_time))
	{
		philo_lock_forks(this_philo->fork_left, this_philo->fork_right);
		
		philo_action_and_print(start_time, this_philo->index, "has taken a fork\n", 0);
				// printf("%04d %d has taken a fork\n", get_diff_time(start_time, end_time),this_philo->index);

		philo_action_and_print(start_time, this_philo->index, "is eating\n", this_philo->get_parse[TIME_TO_EAT]);
				// printf("%04d %d is eating\n", get_diff_time(start_time, end_time),this_philo->index);
				// ms_usleep(this_philo->get_parse[TIME_TO_EAT]);

		philo_unlock_forks(this_philo->fork_left, this_philo->fork_right);

		philo_action_and_print(start_time, this_philo->index, "is sleeping\n", this_philo->get_parse[TIME_TO_SLEEP]);
				// printf("%04d %d is sleeping\n", get_diff_time(start_time, end_time),this_philo->index);
				// ms_usleep(this_philo->get_parse[TIME_TO_SLEEP]);
		
		philo_action_and_print(start_time, this_philo->index, "is thinking\n", 0);
		// printf("%04d %d is thinking\n", get_diff_time(start_time, end_time),this_philo->index);
	}
	// ---------------- end	---------------------------------------//
	philo_action_and_print(start_time, this_philo->index, "is died\n", 0);
	// printf("%04d %d is died\n", get_diff_time(start_time, end_time),this_philo->index);
	return NULL;
}

static void *philo_monitor_run(void *philos)
{
	pthread_t		*philpsophers_thread;
	t_philo_info	*philpsophers;
	pthread_mutex_t *forks;
	int				*get_parse;
	int				i;

	get_parse = (int *)philos;
	philpsophers_thread = ft_calloc(get_parse[ALL_PHILO_NUMBER], sizeof(pthread_t));
	philpsophers = ft_calloc(get_parse[ALL_PHILO_NUMBER], sizeof(t_philo_info));
	forks = ft_calloc(get_parse[ALL_PHILO_NUMBER], sizeof(pthread_mutex_t));
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		philo_init(i, get_parse, &philpsophers[i], forks);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		pthread_create(&philpsophers_thread[i], NULL, philo_run, &philpsophers[i]);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		if(pthread_join(philpsophers_thread[i], NULL) != 0)
			print_error(1);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		pthread_mutex_destroy(&forks[i]);
	return (NULL);
}

void	run_thread(int *get_parse)
{
	pthread_t		philo_monitor;
	int				i;

	pthread_create(&philo_monitor, NULL, philo_monitor_run, get_parse);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
	{
		if (pthread_join(philo_monitor, NULL) == 0)
			printf("[%d thread is return !! ]\n", i);
		else
			print_error(1);
	}
}
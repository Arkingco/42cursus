/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/25 20:50:43 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init(int philo_index, int *get_parse, t_philo_info *philo_info, pthread_mutex_t *forks)
{
	philo_info->index = philo_index;
	philo_info->fork_left = &forks[philo_index];
	philo_info->fork_right = &forks[(philo_index + 1) % get_parse[ALL_PHILO_NUMBER]];
	philo_info->get_parse = get_parse;
	philo_info->die_flag = 0;
	philo_info->first_eat = 1;
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

void philo_action_and_print(timeval start_time, t_philo_info *this_philo, char *strs, int action_flag)
{
	int		diff_time;

	if (this_philo->first_eat == 1 || action_flag == TIME_TO_EAT)
	{
		gettimeofday(&this_philo->last_eat, NULL);
		this_philo->first_eat = 0;
	}
	else
	{
		printf("%d  %d \n", get_diff_time(this_philo->last_eat), this_philo->get_parse[TIME_TO_DIE]);
		if(get_diff_time(this_philo->last_eat) >= this_philo->get_parse[TIME_TO_DIE])
		{
			printf("%d philo is dead !!! ", this_philo->index);
			this_philo->die_flag = 1;
			
		}
	}
	if (this_philo->die_flag)
		return ;
	diff_time = get_diff_time(start_time);
	printf("%04d %d %s", diff_time, this_philo->index, strs);
	if(action_flag != 0)
		ms_usleep(this_philo->get_parse[action_flag]);
}

static void	*philo_run(void *philos)
{
	t_philo_info	*this_philo;
	timeval			start_time;

	this_philo = (t_philo_info *)philos;
	gettimeofday(&start_time, NULL);
	if (this_philo->index % 2 == 0)
		usleep(200);
	while (this_philo->die_flag != 1)
	{
		philo_lock_forks(this_philo->fork_left, this_philo->fork_right);
		philo_action_and_print(start_time, this_philo, "has taken a fork\n", 0);
		philo_action_and_print(start_time, this_philo, "is eating\n", TIME_TO_EAT);
		philo_unlock_forks(this_philo->fork_left, this_philo->fork_right);
		philo_action_and_print(start_time, this_philo, "is sleeping\n", TIME_TO_SLEEP);
		philo_action_and_print(start_time, this_philo, "is thinking\n", 0);
	}
	philo_action_and_print(start_time, this_philo, "is died\n", 0);
	return NULL;
}

static void *philo_monitor_run(void *philos)
{
	pthread_t		*philosophers_thread;
	t_philo_info	*philosophers;
	pthread_mutex_t *forks;
	int				*get_parse;
	int				i;

	get_parse = (int *)philos;
	philosophers_thread = ft_calloc(get_parse[ALL_PHILO_NUMBER], sizeof(pthread_t));
	philosophers = ft_calloc(get_parse[ALL_PHILO_NUMBER], sizeof(t_philo_info));
	forks = ft_calloc(get_parse[ALL_PHILO_NUMBER], sizeof(pthread_mutex_t));
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		philo_init(i, get_parse, &philosophers[i], forks);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		pthread_create(&philosophers_thread[i], NULL, philo_run, &philosophers[i]);
	i = 0;
	while(philosophers[i].die_flag != 0)
	{
		if(i == get_parse[ALL_PHILO_NUMBER] - 1)
			i = -1;
		printf("wait philo . . .");
	}
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		if(pthread_join(philosophers_thread[i], NULL) != 0)
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
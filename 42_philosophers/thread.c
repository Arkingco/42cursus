/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/20 05:14:20 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>

static void	philo_init(int philo_index, int all_number_of_philo, t_philo_info *philo_info, pthread_mutex_t *forks)
{
	philo_info->my_philo_index = philo_index;
	philo_info->fork_left = forks[philo_index];
	philo_info->fork_left = forks[all_number_of_philo % (philo_index + 1)];
}

static void	*print_thread_function(void *philos)
{
	t_philo_info *this_philo = (t_philo_info *)philos;
	printf("%d \n", this_philo->my_philo_index);
	return NULL;
}

void	run_thread(int *get_parse)
{
	pthread_t		*philpsophers_thread;
	t_philo_info	*philpsophers;
	pthread_mutex_t *forks;
	int				i;

	philpsophers_thread = ft_calloc(get_parse[ALL_PHILO_NUMBER], sizeof(pthread_t));
	philpsophers = ft_calloc(get_parse[ALL_PHILO_NUMBER], sizeof(t_philo_info));
	forks = ft_calloc(get_parse[ALL_PHILO_NUMBER], sizeof(pthread_mutex_t));
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		philo_init(i, get_parse[ALL_PHILO_NUMBER], &philpsophers[i], forks);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		pthread_create(&philpsophers_thread[i], NULL, print_thread_function, &philpsophers[i]);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
	{
		if(pthread_join(philpsophers_thread[i], NULL) == 0)
			printf("[%d thread is return !! ]\n", i);
	}
}
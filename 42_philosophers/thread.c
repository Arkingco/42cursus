/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/22 18:01:16 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init(int philo_index, int all_number_of_philo, t_philo_info *philo_info, pthread_mutex_t *forks)
{
	philo_info->my_philo_index = philo_index;
	philo_info->fork_left = &forks[philo_index];
	philo_info->fork_right = &forks[(philo_index + 1) % all_number_of_philo];
	printf("init %d\n",  (philo_index + 1) % all_number_of_philo) ;
}

static void	*philo_run(void *philos)
{
	t_philo_info *this_philo = (t_philo_info *)philos;
	if (this_philo->my_philo_index % 2 == 0)
		usleep(200);
	pthread_mutex_lock(this_philo->fork_left);
	pthread_mutex_lock(this_philo->fork_right);
    //======== start critical section =============

	struct timeval startTime, endTime;
   	double diffTime;
	gettimeofday(&startTime, NULL);
      // 특정 작업 수행
	sleep(1);
	printf("number of %d philosophers is run", this_philo->my_philo_index);
    gettimeofday(&endTime, NULL);
    diffTime = ( endTime.tv_sec - startTime.tv_sec ) + (( endTime.tv_usec - startTime.tv_usec ) / 1000000);
    printf("%lf s    diff time to second = %ld    ---   diff time to usec = %d \n", diffTime,( endTime.tv_sec - startTime.tv_sec ), endTime.tv_usec);
    //========= end   critical section ============
    pthread_mutex_unlock(this_philo->fork_left);
	pthread_mutex_unlock(this_philo->fork_right);
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
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		philo_init(i, get_parse[ALL_PHILO_NUMBER], &philpsophers[i], forks);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		pthread_create(&philpsophers_thread[i], NULL, philo_run, &philpsophers[i]);
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
	{
		if(pthread_join(philpsophers_thread[i], NULL) == 0)
			printf("[%d thread is return !! ]\n", i);
	}
	i = -1;
	while (++i < get_parse[ALL_PHILO_NUMBER])
		pthread_mutex_destroy(&forks[i]);
}
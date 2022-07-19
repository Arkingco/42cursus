/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:06 by kipark            #+#    #+#             */
/*   Updated: 2022/07/19 15:51:28 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_thread()
{
	pthread_t	tid;
	int			i;

	i = 0;
	tid = pthread_self();
	printf("tid : %x \n", (int)tid);
	while(i < 10)
	{
		printf("	tid: %x %d\n", (int)tid, i);
		++i;
		sleep(1);
	}
	return NULL;
}

void	run_thread()
{
	pthread_t	thread_join;
	pthread_t	thread_detach;

	pthread_create(&thread_join, NULL, print_thread, NULL);
	pthread_create(&thread_detach, NULL, print_thread, NULL);
	int i = 0;
	printf("tid : %x \n", (int)pthread_self());
	while(i < 5)
	{
		printf("main:%x %d\n", (int)pthread_self(), i);
		++i;
		sleep(1);
	} 
	pthread_detach(thread_detach);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:13:51 by kipark            #+#    #+#             */
/*   Updated: 2022/08/04 20:37:37 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main()
{
	sem_t 	*sem;
	pid_t 	pid;
	pid_t	wait_pid;
	int 	ret;
	sem_t 	*sem;
	sem = sem_open("test_sem", O_CREAT | O_EXCL , 0644, 200); 
	if (sem == (sem_t *)-1)
	{
		sem_unlink("test_sem");
		sem = sem_open("test_sem", O_CREAT | O_EXCL , 0644, 200); 
	}


	for (int i=0 ; i<1000; ++i)
	{
		pid = fork();
		if (pid == -1)
			break ;
		if (pid == 0)
		{
			sem_wait(sem);
			sleep(1);
			printf("hi %d\n", i);
			sem_post(sem);
			exit(1);
		}
	}
	for(int i=0; i<1000; ++i)
	{
		wait_pid = wait(0);
	}
	ret = sem_close(sem); // 세마포어 종료 및 할당한 자원 해제
	printf("sem_close: %d\n", ret);
	ret = sem_unlink("test_sem"); // 세마포어 객체 해제
	printf("sem_unlink: %d\n", ret);
	return (0);
}
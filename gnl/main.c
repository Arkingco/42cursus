/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:21:40 by kipark            #+#    #+#             */
/*   Updated: 2022/01/15 23:30:35 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	// fd : stdin
	
	// int i;
	// int fd = 0;
	// int read_byte;

	// i = 1;
	// read_byte = 0;
	// argv[0] = "test";
	// argc = 1;
	// char *str = NULL;
	// while(1)  	
	// {
	// 	if(fd == 0)
	// 	{
	// 		str = get_next_line(fd);
	// 		printf("%s", str);
	// 	}
	// 	if(str == NULL)
	// 		break ;
	// }

	// fd : fd > 2
	int argvi;
 
	argvi = 1;
	int fd[8193];
	if(argc > 1)
	{
		while(argv[argvi])
		{
			fd[argvi] = open(argv[argvi], O_RDONLY);
			++argvi;
		}

		char *str;
		int str_plag;
		
		str = NULL;
		str_plag = 1;
		while(str_plag)
		{
			str_plag = 0;
			for(int i=1; i<argvi; ++i)
			{
				str = get_next_line(fd[i]);
				if(str != NULL)
				{
					printf("%s", str);
					str_plag = 1;
				}
				str = NULL;
			}
		}
	}
}

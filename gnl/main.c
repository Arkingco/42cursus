/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:21:40 by kipark            #+#    #+#             */
/*   Updated: 2022/01/14 20:50:52 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	// fd : stdin
	//
	// int i;
	// int fd = 0;
	// int read_byte;

	// i = 1;
	// read_byte = 0;
	// argv[0] = "das";
	// while(i < argc)  	
	// {
	// 	if(fd == 0)
	// 	{
	// 		char *str = get_next_line(fd);
	// 		printf("%s", str);
	// 	}
	// 	++i;
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
		while(1)
		{
			for(int i=0; i<argvi; ++i)
			{
				char *str = get_next_line(fd[i]);
				if(!str)
				{
					printf("%s", str);
				}
			}
		}
	}
	
}

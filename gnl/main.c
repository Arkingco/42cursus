/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:21:40 by kipark            #+#    #+#             */
/*   Updated: 2022/01/10 16:57:15 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

#define PI 0.5

int main(int argc, char *argv[])
{
	int i;
	int fd;
	int read_byte;
	
	i = 1;
	read_byte = 0;
	while(i < argc)  	
	{
		if(0 < (fd = open(argv[1], O_RDONLY)))
		{
			char *str = get_next_line(fd);
			while(str != NULL)
			{
				printf("%s", str);
				str = get_next_line(fd);
			}
		}
		else
		{
			printf("%s", get_next_line(0));
		}
		i++;

		
	}
}

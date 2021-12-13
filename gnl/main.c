/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:21:40 by kipark            #+#    #+#             */
/*   Updated: 2021/12/13 21:51:55 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

#define BUFF_SIZE 1

int main(int argc, char *argv[])
{	
	char buff[BUFF_SIZE];
	int i;
	int fd;
	int read_byte;
	
	i = 1;
	read_byte = 0;
	while(i < argc)
	{
		if(0 < (fd = open(argv[1], O_RDONLY)))
		{
			while(read_byte = read( fd, buff, BUFF_SIZE) != 0)
			{
				write(1, buff, BUFF_SIZE);
				write(1, "\n", 1);
			}
		}
		++i;
	}

	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:21:40 by kipark            #+#    #+#             */
/*   Updated: 2021/12/15 20:44:27 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

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
			printf("count\n");
			get_next_line(fd);
		}
		++i;
	}
}

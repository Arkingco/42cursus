/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:21:40 by kipark            #+#    #+#             */
/*   Updated: 2022/01/06 14:15:24 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>
#include<fcntl.h>

#define BUFFER_SIZE 40

int main(int argc, char *argv[])
{
	int i;
	int fd;
	int read_byte;

	char *end_of_file_set = "end\n";
	i = 1;
	read_byte = 0;
	while(i < argc)  	
	{
		if(0 < (fd = open(argv[1], O_RDONLY)))
		{
			while(get_next_line(fd) != end_of_file_set)
			{
				get_next_line(fd);
			}
		}
		++i;
		
	}
}

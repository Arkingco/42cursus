/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:21:40 by kipark            #+#    #+#             */
/*   Updated: 2021/12/21 20:56:36 by kipark           ###   ########seoul.kr  */
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
	char buffer[BUFFER_SIZE];


	i = 1;
	read_byte = 0;
	while(i < argc)  	
	{
		if(0 < (fd = open(argv[1], O_RDONLY)))
		{
			get_next_line(fd);
		}
		++i;
		
	}
}

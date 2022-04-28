/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:31:15 by kipark            #+#    #+#             */
/*   Updated: 2022/04/28 19:13:42 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include "so_long.h"

int main(int argc, char **argv)
{
    char **str;
    int fd = 0;
    
	fd = open(argv[1], O_RDONLY);
	printf("%s %d\n", argv[1], fd);
	while (1)
	{
        char *gnl_str = get_next_line(fd);
        if(gnl_str == NULL)
            break ;
		printf("%s", gnl_str);
	}
	close(fd);
}
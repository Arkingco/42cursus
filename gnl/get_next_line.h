/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:16:22 by kipark            #+#    #+#             */
/*   Updated: 2021/12/14 17:03:58 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<unistd.h>
#include<stdlib.h>

typedef struct gnl_list
{
	char				*content;
	struct	gnl_list	*next;
}	g_list;

int ft_strchr(char *s, char word);
int ft_strlen(char *s);
char *get_next_line(int fd);

#endif
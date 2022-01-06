/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:16:22 by kipark            #+#    #+#             */
/*   Updated: 2022/01/06 14:34:14 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<unistd.h>
#include<stdlib.h>

int gnl_strchr(char *s, char word);
int gnl_strlen(char *s);
char *gnl_strjoin(char *static_line, char *buffer, int buffer_length);
char *get_next_line(int fd);

#endif
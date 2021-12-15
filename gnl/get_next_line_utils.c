/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:27:48 by kipark            #+#    #+#             */
/*   Updated: 2021/12/15 21:15:46 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int ft_strchr(char *s, char word)
{
	int i;

	i = 0;
	while(s[i] != '\0')
	{
		if(s[i] == word)
			return (i+1);
		++i;
	}
	return (0);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i] != '\0')
		++i;
	return(i);
}
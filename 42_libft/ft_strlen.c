/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:15:32 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:15:00 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
	{
		++length;
	}
	return (length);
}

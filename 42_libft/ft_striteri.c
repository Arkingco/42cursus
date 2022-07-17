/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:03:46 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:59 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	s_length;
	int	i;

	s_length = ft_strlen(s);
	i = 0;
	while (i < s_length)
	{
		f(i, &s[i]);
		++i;
	}
}

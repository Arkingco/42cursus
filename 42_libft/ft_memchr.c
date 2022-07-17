/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:20:39 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:49 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*in_s;
	size_t			i;

	i = 0;
	in_s = (unsigned char *)s;
	while (i < n)
	{
		if (in_s[i] == (unsigned char)c)
			return ((void *)in_s + i);
		++i;
	}
	return ((void *)0);
}

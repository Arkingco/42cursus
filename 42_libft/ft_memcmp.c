/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:37:55 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:50 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t size_n)
{
	size_t			i;
	unsigned char	*in_s1;
	unsigned char	*in_s2;

	i = 0;
	in_s1 = (unsigned char *)s1;
	in_s2 = (unsigned char *)s2;
	while (i < size_n)
	{
		if (in_s1[i] != in_s2[i])
			return (in_s1[i] - in_s2[i]);
		++i;
	}
	return (0);
}

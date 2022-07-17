/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:57:27 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:51 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*idst;
	const unsigned char	*isrc;
	size_t				i;

	if ((!dst && !src) && n)
		return (0);
	i = 0;
	idst = (unsigned char *)dst;
	isrc = (const unsigned char *)src;
	while (i < n)
	{
		idst[i] = isrc[i];
		++i;
	}
	return (idst);
}

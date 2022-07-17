/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:38:23 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:51 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*in_dst;
	unsigned char	*in_src;
	size_t			i;

	if ((!dst && !src) && len)
		return (0);
	i = 0;
	in_dst = (unsigned char *) dst;
	in_src = (unsigned char *) src;
	if (in_dst < in_src)
	{
		while (len--)
			*in_dst++ = *in_src++;
	}
	else
	{
		in_dst = in_dst + len - 1;
		in_src = in_src + len - 1;
		while (len--)
			*in_dst-- = *in_src--;
	}
	return (dst);
}

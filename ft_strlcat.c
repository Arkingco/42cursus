/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:19:07 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:15:00 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_length;
	size_t	src_length;

	i = 0;
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dst_length >= dstsize)
		return (src_length + dstsize);
	while (src[i] != '\0' && dstsize > (dst_length + 1 + i))
	{
		dst[dst_length + i] = src[i];
		++i;
	}
	dst[dst_length + i] = '\0';
	if (dst_length >= dstsize)
		return (src_length + dstsize);
	return (dst_length + src_length);
}

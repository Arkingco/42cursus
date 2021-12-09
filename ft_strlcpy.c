/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:19:07 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:15:00 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_length;

	i = 0;
	src_length = ft_strlen(src);
	while (src[i] != '\0' && dstsize > i + 1)
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_length);
}

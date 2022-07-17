/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:44:33 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:52 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pointer;

	i = 0;
	pointer = (unsigned char *)b;
	while (i < len)
	{
		pointer[i] = (unsigned char)c;
		++i;
	}
	return ((void *)pointer);
}

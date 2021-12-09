/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:13:53 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:15:03 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*is1;
	unsigned char	*is2;
	size_t			i;

	i = 0;
	is1 = (unsigned char *)s1;
	is2 = (unsigned char *)s2;
	while (i < n)
	{
		if (is1[i] != is2[i] || is1[i] == 0 || is2[i] == 0)
			return (is1[i] - is2[i]);
		++i;
	}
	return (0);
}

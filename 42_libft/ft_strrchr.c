/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:19:17 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:15:04 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	size_t	i;

	last = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			last = (char *)&s[i];
		}
		++i;
	}
	if (s[i] == (unsigned char)c)
		last = (char *)&s[i];
	if (last)
		return (last);
	return (0);
}

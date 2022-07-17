/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:15:56 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:15:05 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	s_length;

	s_length = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (start < s_length && s[start] != '\0' && len > i)
	{
		str[i] = s[start];
		++i;
		++start;
	}
	str[i] = '\0';
	return (str);
}

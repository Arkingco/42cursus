/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:10:44 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:15:04 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (start < end && end - 1 >= 0 && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return ((char *)str);
}

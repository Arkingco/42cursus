/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 03:25:39 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:58 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s1_length;

	s1_length = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (s1_length + 1));
	if (ptr == 0)
		return (0);
	ft_strlcpy(ptr, s1, s1_length + 1);
	return (ptr);
}

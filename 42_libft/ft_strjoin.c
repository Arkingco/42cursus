/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:42:19 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:59 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_length;
	int		s2_length;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_length + s2_length + 1));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, s1_length + 1);
	ft_strlcat(str, s2, s1_length + s2_length + 1);
	return (str);
}

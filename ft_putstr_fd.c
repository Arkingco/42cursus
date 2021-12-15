/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:19:04 by kipark            #+#    #+#             */
/*   Updated: 2021/12/09 19:14:56 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h" 

void	ft_putstr_fd(char *s, int fd)
{
	int	s_length;

	s_length = ft_strlen(s);
	write(fd, s, s_length);
}

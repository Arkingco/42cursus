/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 05:58:29 by kipark            #+#    #+#             */
/*   Updated: 2022/05/08 06:00:32 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t str_len(char *str)
{
	int length;

	length = 0;
	while(str[length] != '\0')
		length++;
	return (length);
}

void print_error(char *str)
{
	write(2, str, str_len(str));
	exit(1);
}
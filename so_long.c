/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:01:26 by kipark            #+#    #+#             */
/*   Updated: 2022/04/28 20:21:23 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<stdio.h>

int	main(int argc, char **argv)
{
	t_list	*str_head;
	char	**pared_str;

	if (argc < 2)
		return (0);
	str_head = NULL;
	pared_str = parse(&str_head, argv);
	// 그림 찍어야함
}

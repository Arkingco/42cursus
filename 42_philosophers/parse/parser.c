/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:36:24 by kipark            #+#    #+#             */
/*   Updated: 2022/07/18 21:50:47 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void set_return_parse(int *return_parse, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		return_parse[i] = parse_atoi(argv[i]);
		++i;
	}
}

int	*parse(int argc, char **argv)
{
	int *return_parse;
	
	return_parse = (int *)malloc(sizeof(int) * (argc));
	if (return_parse == NULL)
		return (0);
	if (paser_error(argv))
		print_error(1);
	set_return_parse(return_parse, argc, argv);
	for(int i=0; i<argc; ++i)
		printf("%d \n", return_parse[i]);
	return (return_parse);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:36:24 by kipark            #+#    #+#             */
/*   Updated: 2022/07/18 21:24:47 by kipark           ###   ########.fr       */
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
	if (return_parse == (void *)0)
		return (0);
	if (paser_error(argv))
		print_error(1);
	set_return_parse(return_parse, argc, argv);
	for(int i=0; i<argc; ++i)
	{
		printf("%d \n", return_parse[i]);
	}
	return (return_parse);
}
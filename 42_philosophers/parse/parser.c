/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:36:24 by kipark            #+#    #+#             */
/*   Updated: 2022/07/27 21:59:35 by kipark           ###   ########.fr       */
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
	
	return_parse = ft_calloc(argc - 1, sizeof(int));
	if (paser_error(argv))
		print_error(1);
	set_return_parse(return_parse, argc, argv);
	return (return_parse);
}
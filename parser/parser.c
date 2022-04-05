/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:36:13 by kipark            #+#    #+#             */
/*   Updated: 2022/04/05 15:36:22 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void	set_return_value(long int *return_arvg_to_int, char **input_argv_to_str, int parse_size)
{
	int idx;

	idx = 0;
	while (idx < parse_size)
	{
		return_arvg_to_int[idx] = parse_atoi(input_argv_to_str[idx]);
		idx++;
	}
	return_arvg_to_int[idx] = INT64_MIN;
}

long int	*parser(char *s)
{
	char		**input_argv_to_str;
	long int 	*return_arvg_to_int;
	int			parse_size;

	input_argv_to_str = push_swap_parser_split(s, ' ');
	if (paser_error(input_argv_to_str))
		return (0);
	parse_size = parse_row_length(input_argv_to_str);
	return_arvg_to_int = malloc(sizeof(long int) * (parse_size + 1));
	if (return_arvg_to_int == NULL)
		return (0);
	set_return_paser_value(return_arvg_to_int, input_argv_to_str, parse_size);
	return (return_arvg_to_int);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:36:13 by kipark            #+#    #+#             */
/*   Updated: 2022/04/04 22:18:48 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

void set_return_paser_value(long int *was_parsed, char **need_parsed, int parse_size)
{
	int idx;

	idx = 0;
	while(idx < parse_size)
	{
		was_parsed[idx] = parse_atoi(need_parsed[idx]);
		idx++;
	}
	was_parsed[idx] = INT64_MIN;
}

long int *parser(char *s)
{
	char 	**need_parsed;
	long int 	*was_parsed;
	int		parse_size;

	need_parsed = push_swap_parser_split(s, ' ');
	if(paser_error(need_parsed))
		return (0);
	parse_size = parse_row_length(need_parsed);
	was_parsed = malloc(sizeof(long int) * (parse_size + 1));
	if (was_parsed == NULL)
		return (0);
	set_return_paser_value(was_parsed, need_parsed, parse_size);
	return (was_parsed);
}
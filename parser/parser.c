/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:36:13 by kipark            #+#    #+#             */
/*   Updated: 2022/04/03 17:42:08 by kipark           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

long int *push_swap_parse(char *s)
{
	char 	**need_parsed;
	int 	*was_parsed;
	int		parse_size;
	int		idx;

	need_parsed = push_swap_parser_split(s, ' ');
	parse_size = need_parse_length(need_parsed);
	was_parsed = malloc(sizeof(int) * parse_size + 1);
	if (was_parsed == NULL)
		return (0);
	idx = 0;
	while(idx + 1 < parse_size)
	{
		was_parsed[idx] = parse_atoi(need_parsed[idx]);
		idx++;
	}
}
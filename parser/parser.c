/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:36:13 by kipark            #+#    #+#             */
/*   Updated: 2022/04/23 19:52:29 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"

static void	set_paser(long int *arvg_to_int, char **argv_to_str, int arr_length)
{
	int	idx;

	idx = 0;
	while (idx < arr_length)
	{
		arvg_to_int[idx] = parse_atoi(argv_to_str[idx]);
		idx++;
	}
	arvg_to_int[idx] = INT64_MIN;
}

long int	*parser(char *s)
{
	char		**argv_to_str;
	long int	*arvg_to_int;
	int			arr_length;

	argv_to_str = push_swap_parser_split(s, ' ');
	if (paser_error(argv_to_str))
		print_error(1);
	arr_length = parse_row_length(argv_to_str);
	arvg_to_int = malloc(sizeof(long int) * (arr_length + 1));
	if (arvg_to_int == NULL)
		print_error(1);
	set_paser(arvg_to_int, argv_to_str, arr_length);
	push_swap_double_arr_free(argv_to_str);
	return (arvg_to_int);
}

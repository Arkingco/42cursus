/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:56:55 by baggiseon         #+#    #+#             */
/*   Updated: 2022/08/11 12:12:50 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	*get_parse;

	if (argc != 5 && argc != 6)
		print_error(1);
	get_parse = parse(argc - 1, ++argv);
	run_thread(get_parse);
}

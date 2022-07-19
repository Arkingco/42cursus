/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baggiseon <baggiseon@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:55:13 by kipark            #+#    #+#             */
/*   Updated: 2022/07/20 04:17:51 by baggiseon        ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int argc, char **argv)
{
	int *get_parse;

	if (argc != 5 && argc != 6)
		print_error(1);
	get_parse = parse(argc - 1, ++argv);
	run_thread(get_parse);
}
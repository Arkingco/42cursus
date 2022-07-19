/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:55:13 by kipark            #+#    #+#             */
/*   Updated: 2022/07/19 15:22:27 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int argc, char **argv)
{
	int *get_parse;

	if (argc != 5 && argc != 6)
		print_error(1);
	get_parse = parse(argc - 1, ++argv);
	run_thread();
}
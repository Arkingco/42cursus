/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:13:13 by kipark            #+#    #+#             */
/*   Updated: 2022/05/08 06:00:59 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>

#define P_READ      0
#define P_WRITE     1
#define BUFFER_SIZE	4096

void	print_error(char *str);

# endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:18:29 by kipark            #+#    #+#             */
/*   Updated: 2022/05/09 11:02:42 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex.h"

int	is_slash(char *str)
{
	return (1);
}

void	find_path_cmd(char **cmd)
{

}

char	**cmd_parse(char *cmd_str, char **envp)
{
	char **cmd;

	cmd = pipex_parser_split(cmd_str, ' ');
	if(is_slash(cmd[0]))
		return (cmd);
	else
		find_path_cmd(cmd);
	return (cmd);
}

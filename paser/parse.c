/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:18:29 by kipark            #+#    #+#             */
/*   Updated: 2022/05/09 11:42:58 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex.h"

int	is_slash(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '/')
			return (1);
		++i;
	}
	return (0);
}

char	*find_path_str(char *cmd, char **envp)
{
	int idx;

	idx = 0;
	while (envp[idx] != NULL)
	{
		if(ft_strncmp("PATH=", cmd, PATH_POINTER))
			return ft_strdup(cmd + PATH_POINTER);
		++idx;
	}
}

char	*find_path_cmd(char *cmd, char **envp)
{
	int		idx;
	char	**path_split;
	char	*path_str;
	char	*cmd_path;
	int		status_path;

	path_str = find_path_str(cmd, envp);
	path_split = pipex_parser_split(path_str, ':');
	idx = 0;
	while(path_split[idx] != NULL)
	{
		cmd_path = ft_strjoin(path_split[idx], cmd);
		status_path = access(cmd_path, F_OK);
		if(status_path == -1)
			free(cmd_path);
		if(status_path == 0)
			break;
		idx++;
	}
	// have to frere = path_str 	path_split 
	return (cmd_path);
}

char	**cmd_parse(char *cmd_str, char **envp)
{
	char **cmd;

	cmd = pipex_parser_split(cmd_str, ' ');
	if(is_slash(cmd[0]))
		return (cmd);
	else
		find_path_cmd(cmd, envp);
	return (cmd);
}

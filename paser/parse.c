/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:18:29 by kipark            #+#    #+#             */
/*   Updated: 2022/05/09 11:50:45 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../pipex.h"

static void	str_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		++i;
	}
	free(str[i]);
	free(str);
}

static int	is_slash(char *str)
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
	int		patt_status;

	path_str = find_path_str(cmd, envp);
	path_split = pipex_parser_split(path_str, ':');
	idx = 0;
	while(path_split[idx] != NULL)
	{
		cmd_path = ft_strjoin(path_split[idx], cmd);
		patt_status = access(cmd_path, F_OK);
		if(patt_status == -1)
			free(cmd_path);
		if(patt_status == 0)
			break;
		idx++;
	}
	str_free(path_split);
	free(path_str);
	if (patt_status == -1)
		return (0);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kipark <kipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 09:18:29 by kipark            #+#    #+#             */
/*   Updated: 2022/05/21 15:28:58 by kipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	str_free(char **str)
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
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			return (1);
		++i;
	}
	return (0);
}

char	*find_path_str(char **envp)
{
	int	idx;

	idx = 0;
	while (envp[idx] != NULL)
	{
		if (ft_strncmp("PATH=", envp[idx], PATH_POINTER) == 0)
			return (ft_strdup(envp[idx] + PATH_POINTER));
		++idx;
	}
	return (0);
}

char	*find_path_cmd(char *cmd, char **envp)
{
	int		idx;
	char	**path_split;
	char	*path_str;
	char	*cmd_path;
	int		path_status;

	path_str = find_path_str(envp);
	path_split = ft_split(path_str, ':');
	idx = -1;
	while (path_split[++idx] != NULL)
	{
		cmd_path = ft_strjoin(path_split[idx], cmd);
		if (cmd_path == NULL)
			print_error("ft_strjoin error");
		path_status = access(cmd_path, X_OK);
		if (path_status == 0)
			break ;
		else
			free(cmd_path);
	}
	str_free(path_split);
	free(path_str);
	if (path_status == -1)
		cmd_path = NULL;
	return (cmd_path);
}

char	**cmd_parse(char *stdin_cmd_str, char **envp)
{
	char	**cmd;
	char	*find_path;

	cmd = ft_split(stdin_cmd_str, ' ');
	if (stdin_cmd_str[0] == '\0')
		return (cmd);
	if (is_slash(cmd[0]))
		return (cmd);
	else
	{
		find_path = find_path_cmd(cmd[0], envp);
		if (find_path == NULL)
			return (cmd);
		free(cmd[0]);
		cmd[0] = 0;
		cmd[0] = find_path;
	}
	return (cmd);
}

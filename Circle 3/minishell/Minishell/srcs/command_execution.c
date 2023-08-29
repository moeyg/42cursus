/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:01:14 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:28:38 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**extract_path(t_cmd_line *cmd_line, int index)
{
	t_cmd	*cmd;
	char	**extracted;
	char	*prompt;
	int		i;

	cmd = pipe_command(cmd_line, index);
	extracted = 0;
	i = 0;
	while (cmd && cmd->type != PIPE)
	{
		if (cmd->type == CMD)
		{
			prompt = ft_strdup(cmd->input);
			extracted = append_env_array(extracted, prompt, ++i);
		}
		if (cmd->type == REDIRECTION)
			cmd = cmd->next;
		cmd = cmd->next;
	}
	return (extracted);
}

t_cmd	*pipe_command(t_cmd_line *cmd_line, int index)
{
	int		i;
	t_cmd	*cmd;

	cmd = cmd_line->cmd;
	i = 0;
	while (cmd && i < index)
	{
		if (cmd->type == PIPE)
			i++;
		cmd = cmd->next;
	}
	return (cmd);
}

char	*executable_path(char **search_path, char *cmd)
{
	char	*path;
	char	*executable;
	int		fd;
	int		i;

	i = -1;
	if (access(cmd, X_OK) != -1)
		return (cmd);
	if (!search_path)
		print_error(cmd, 127, 1);
	path = ft_strjoin("/", cmd);
	while (search_path[++i])
	{
		executable = ft_strjoin(search_path[i], path);
		fd = access(executable, X_OK);
		if (fd != -1)
		{
			free(path);
			return (executable);
		}
		free(executable);
	}
	close(fd);
	free(path);
	return (0);
}

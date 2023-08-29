/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:04:33 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:27:25 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_preceding_spaces(t_cmd_line *line, t_cmd **cmd, char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i] && ft_isspace(prompt[i]))
		i++;
	if (!prompt[i])
		return (delete_command(line, cmd));
	if (i != 0)
		(*cmd)->space = 1;
	(*cmd)->input = ft_strdup(prompt + i);
	free(prompt);
	prompt = (*cmd)->input;
	split_command_space(cmd, prompt);
}

void	split_command_space(t_cmd **cmd, char *prompt)
{
	t_cmd	*command;
	int		i;

	i = 0;
	while (prompt[i])
	{
		if (ft_isspace(prompt[i]))
		{
			(*cmd)->input = ft_substr(prompt, 0, i);
			command = split_command(cmd);
			command->input = ft_strdup(prompt + i);
			free(prompt);
			if ((*cmd)->space == 1)
				(*cmd)->space = 3;
			else
				(*cmd)->space = 2;
			return ;
		}
		i++;
	}
}

int	validate_space(char *prompt)
{
	while (*prompt)
	{
		if (ft_isspace(*prompt))
			return (1);
		prompt++;
	}
	return (0);
}

void	seperate_space(t_cmd_line *cmd_line)
{
	t_cmd	*cmd;
	char	*prompt;

	cmd = cmd_line->cmd;
	while (cmd)
	{
		if (cmd->type == 0 && !cmd->quote)
		{
			if (validate_space(cmd->input))
			{
				prompt = cmd->input;
				process_preceding_spaces(cmd_line, &cmd, prompt);
			}
		}
		cmd = cmd->next;
	}
}

int	is_space(char *command)
{
	while (*command)
	{
		if (*command != 32 && !(*command >= 9 && *command <= 13))
			return (0);
		command++;
	}
	return (1);
}

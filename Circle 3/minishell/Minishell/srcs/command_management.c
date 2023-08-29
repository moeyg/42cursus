/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 23:00:22 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:28:40 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*create_command(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		print_error("malloc error", 1, 1);
	cmd->input = 0;
	cmd->dollar = 0;
	cmd->type = 0;
	cmd->pipe = 0;
	cmd->status = g_env->status;
	cmd->quote = 0;
	cmd->space = 0;
	cmd->heredoc = 0;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*append_command(t_cmd_line *cmd_line)
{
	t_cmd	*cmd;

	if (cmd_line->cmd == NULL)
	{
		cmd_line->cmd = create_command();
		return (cmd_line->cmd);
	}
	cmd = cmd_line->cmd;
	while (cmd->next)
		cmd = cmd->next;
	cmd->next = create_command();
	return (cmd->next);
}

void	delete_command(t_cmd_line *cmd_line, t_cmd **cmd)
{
	t_cmd	*previous;

	previous = cmd_line->cmd;
	if ((*cmd) == cmd_line->cmd)
	{
		cmd_line->cmd = (*cmd)->next;
		free((*cmd)->input);
		free(*cmd);
		return ;
	}
	while (previous->next != *cmd)
		previous = previous->next;
	previous->next = (*cmd)->next;
	free((*cmd)->input);
	free(*cmd);
	(*cmd) = previous;
}

t_cmd	*split_command(t_cmd **cmd)
{
	t_cmd	*command;

	command = create_command();
	command->next = (*cmd)->next;
	(*cmd)->next = command;
	return (command);
}

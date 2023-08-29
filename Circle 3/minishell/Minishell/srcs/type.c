/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:55:35 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:27:01 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_command_type(t_cmd_line *cmd_line)
{
	t_cmd	*cmd;
	char	*prompt;
	int		i;

	i = 0;
	cmd = cmd_line->cmd;
	while (cmd)
	{
		if (cmd->quote == 0)
		{
			i = 0;
			while (cmd->input[i])
			{
				if (command_type(cmd->input, i))
				{
					prompt = cmd->input;
					identify_type(&cmd, prompt, command_type(cmd->input, i), i);
					free(prompt);
					break ;
				}
				i++;
			}
		}
		cmd = cmd->next;
	}
}

void	identify_type(t_cmd **cmd, char *prompt, int size, int i)
{
	t_cmd	*command;

	if (i != 0)
	{
		(*cmd)->input = ft_substr(prompt, 0, i);
		command = split_command(cmd);
		command->input = ft_substr(prompt, i, size);
		(*cmd) = (*cmd)->next;
	}
	else if (i == 0)
		(*cmd)->input = ft_substr(prompt, 0, size);
	if (prompt[i] == '|')
		(*cmd)->type = 2;
	else
		(*cmd)->type = 1;
	if (prompt[i + size])
	{
		command = split_command(cmd);
		command->input = ft_strdup(prompt + i + size);
	}
}

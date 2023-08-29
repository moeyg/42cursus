/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 23:04:25 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:28:26 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_prompt(t_cmd_line *cmd_line, char *prompt)
{
	cmd_line->size = 1;
	cmd_line->syntax = 0;
	cmd_line->cmd = NULL;
	if (!quote_balanced(prompt))
	{
		syntax_error("syntax error", 1, 0);
		return (0);
	}
	tokenize(cmd_line, prompt);
	if (cmd_line->syntax)
		return (cmd_line->syntax);
	if (!validate_cmd_syntax(cmd_line))
	{
		syntax_error("syntax error", 1, 0);
		clear_prompt(cmd_line);
		return (0);
	}
	if (!cmd_line->cmd)
	{
		if (cmd_line->cmd)
			clear_prompt(cmd_line);
		g_env->status = 0;
		return (0);
	}
	return (1);
}

void	tokenize(t_cmd_line *cmd_line, char *prompt)
{
	seperate_quote(cmd_line, prompt);
	if (cmd_line->syntax)
		return (syntax_error("syntax error", 1, 0));
	setup_command_type(cmd_line);
	seperate_space(cmd_line);
	dollar_in_command(cmd_line);
	if (!cmd_line->cmd)
		return ;
	merge_quotes(cmd_line);
}

void	merge_quotes(t_cmd_line *cmd_line)
{
	t_cmd	*cmd;
	char	*merged;

	cmd = cmd_line->cmd;
	while (cmd->next)
	{
		if (cmd->space <= 1 && (cmd->next->space == 0 || cmd->next->space == 2))
		{
			if ((!cmd->type && !cmd->next->type) \
				&& (cmd->quote || cmd->next->quote))
			{
				merged = ft_strjoin(cmd->input, cmd->next->input);
				merge_commands(&cmd, merged);
			}
			else
				cmd = cmd->next;
		}
		else
			cmd = cmd->next;
	}
}

void	merge_commands(t_cmd **cmd, char *prompt)
{
	t_cmd	*next_cmd;

	next_cmd = (*cmd)->next;
	if (next_cmd->space == 2 || next_cmd->space == 3)
		(*cmd)->space = 2;
	else
		(*cmd)->space = 0;
	(*cmd)->next = next_cmd->next;
	free_inputs(next_cmd->input, (*cmd)->input, NULL);
	free(next_cmd);
	(*cmd)->quote = 3;
	(*cmd)->input = prompt;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 02:42:06 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/29 21:28:41 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollar_in_command(t_cmd_line *cmd_line)
{
	t_cmd	*tmp;
	t_cmd	*cmd;

	cmd = cmd_line->cmd;
	tmp = 0;
	while (cmd)
	{
		if (cmd->quote != 1)
		{
			cmd->dollar = count_dollars(cmd->input);
			if (cmd->dollar)
			{
				cmd->input = convert_dollars(cmd->input, cmd->dollar);
				if (!cmd->input[0] && cmd->quote == 0 && tmp && tmp->type != 1)
				{
					delete_command(cmd_line, &cmd);
					if (!cmd_line->cmd)
						return ;
				}
			}
		}
		tmp = cmd;
		if (cmd)
			cmd = cmd->next;
	}
}

int	command_type(char *prompt, int i)
{
	if (prompt[i] == '|')
	{
		return (1);
	}
	else if ((!ft_strncmp(prompt + i, ">>", 2)) \
		|| (!ft_strncmp(prompt + i, "<<", 2)))
	{
		return (2);
	}
	else if ((prompt[i] == '>') || (prompt[i] == '<'))
	{
		return (1);
	}
	return (CMD);
}

int	validate_cmd_syntax(t_cmd_line *cmd_line)
{
	t_cmd	*cmd;

	cmd = cmd_line->cmd;
	if (cmd && cmd->type == PIPE)
		return (0);
	while (cmd)
	{
		if (cmd->type)
		{
			if (cmd->type && !cmd->next)
				return (0);
			else if (cmd->type == cmd->next->type)
				return (0);
			else if (cmd->type == 1 && cmd->next->type)
				return (0);
		}
		cmd = cmd->next;
	}
	return (1);
}

int	quote_balanced(char *prompt)
{
	int	quote_state;
	int	i;

	i = 0;
	quote_state = NO_QUOTE;
	while (prompt[i])
	{
		if (prompt[i] == '\'' && quote_state == NO_QUOTE)
			quote_state = SINGLE_QUOTE;
		else if (prompt[i] == '\"' && quote_state == NO_QUOTE)
			quote_state = DOUBLE_QUOTE;
		else if (prompt[i] == '\'' && quote_state == SINGLE_QUOTE)
			quote_state = NO_QUOTE;
		else if (prompt[i] == '\"' && quote_state == DOUBLE_QUOTE)
			quote_state = NO_QUOTE;
		i++;
	}
	if (quote_state != NO_QUOTE)
		return (0);
	return (1);
}

int	find_closing_quote(char *prompt)
{
	int		closing;
	char	openning;

	closing = 1;
	openning = prompt[0];
	while (prompt[closing] && prompt[closing] != openning)
	{
		closing++;
	}
	if (!prompt[closing])
		return (-1);
	return (closing - 1);
}

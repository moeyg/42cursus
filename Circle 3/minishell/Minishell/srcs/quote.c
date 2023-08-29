/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:54:28 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:57:39 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	seperate_quote(t_cmd_line *line, char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == '\"')
			i += process_double_quote(line, prompt + i);
		else if (prompt[i] == '\'')
			i += process_single_quote(line, prompt + i);
		else
			i += process_prompt(line, prompt + i);
		i++;
	}
}

int	process_double_quote(t_cmd_line *line, char *prompt)
{
	t_cmd	*cmd;
	int		i;

	i = 1;
	while (prompt[i] != '\"')
		i++;
	cmd = append_command(line);
	cmd->input = ft_substr(prompt, 1, i - 1);
	cmd->quote = 2;
	return (i);
}

int	process_single_quote(t_cmd_line *line, char *prompt)
{
	t_cmd	*cmd;
	int		i;

	i = 1;
	while (prompt[i] != '\'')
		i++;
	cmd = append_command(line);
	cmd->input = ft_substr(prompt, 1, i - 1);
	cmd->quote = 1;
	return (i);
}

int	process_prompt(t_cmd_line *line, char *prompt)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	while (prompt[i] != '\"' && prompt[i] != '\'' && prompt[i])
	{
		if (prompt[i] == '\\' || prompt[i] == ';')
			line->syntax = 1;
		i++;
	}
	cmd = append_command(line);
	cmd->input = ft_substr(prompt, 0, i);
	return (i - 1);
}

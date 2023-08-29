/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:04:07 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:54:32 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_prompt(t_cmd_line *line)
{
	t_cmd	*current_cmd;
	t_cmd	*next_cmd;

	current_cmd = line->cmd;
	while (current_cmd)
	{
		next_cmd = current_cmd;
		free(current_cmd->input);
		current_cmd = current_cmd->next;
		free(next_cmd);
	}
	line->cmd = 0;
}

void	free_inputs(char *input1, char *input2, char *input3)
{
	free(input1);
	free(input2);
	if (input3)
		free(input3);
}

void	free_command(char **prompt)
{
	int	i;

	i = -1;
	while (prompt[++i])
		free(prompt[i]);
	free(prompt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:48:57 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:57:05 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(int argc, char *argv[], char *envp[], t_cmd_line *cmd_line)
{
	struct termios	terminal;

	(void)argv;
	if (argc != 1)
		print_error("argument input error", 126, 1);
	tcgetattr(STDIN_FILENO, &terminal);
	terminal.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
	initialize_env(envp);
	cmd_line->input = dup(STDIN_FILENO);
	cmd_line->output = dup(STDOUT_FILENO);
}

int	setup_command(t_cmd_line cmd_line, char *prompt)
{
	t_cmd	*cmd;

	if (!setup_heredoc(prompt))
		return (0);
	initialize_signal();
	if (!parse_prompt(&cmd_line, prompt))
		return (0);
	cmd = cmd_line.cmd;
	while (cmd)
	{
		if (cmd->type == PIPE)
			cmd_line.size++;
		cmd = cmd->next;
	}
	if (cmd_line.syntax || setup_execute(&cmd_line) == -2)
	{
		g_env->status = 1;
		clear_prompt(&cmd_line);
		return (0);
	}
	clear_prompt(&cmd_line);
	return (1);
}

void	exit_minishell(void)
{
	ft_putstr_fd("exit\n", 1);
	exit(0);
}

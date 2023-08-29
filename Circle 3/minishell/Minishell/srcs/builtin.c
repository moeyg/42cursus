/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:38:29 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:28:51 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setup_builtin(t_cmd_line *cmd_line)
{
	char	**prompt;
	int		i;

	setup_io_redirection(cmd_line, NULL, 0);
	prompt = extract_path(cmd_line, 0);
	execute_builtin(prompt, cmd_line->size);
	i = -1;
	while (prompt[++i])
		free(prompt[i]);
	free(prompt);
	if (parse_builtin(cmd_line->cmd->input) == 2)
		return (-2);
	backup_std_io(cmd_line);
	return (1);
}

int	parse_builtin(char *prompt)
{
	if (!ft_strlen(prompt))
		return (0);
	if (!ft_strcmp(prompt, "echo"))
		return (1);
	if (!ft_strcmp(prompt, "pwd"))
		return (1);
	if (!ft_strcmp(prompt, "unset"))
		return (1);
	if (!ft_strcmp(prompt, "cd"))
		return (1);
	if (!ft_strcmp(prompt, "export"))
		return (1);
	if (!ft_strcmp(prompt, "exit"))
		return (2);
	if (!ft_strcmp(prompt, "env"))
		return (1);
	return (0);
}

void	execute_echo(char **prompt)
{
	int		has_content;
	int		i;

	has_content = 0;
	if (prompt[1])
	{
		i = 1;
		while (prompt[i])
		{
			if (!validate_option_n(prompt[i]))
				break ;
			i++;
		}
		if (i != 1)
			has_content = 1;
		while (prompt[i])
		{
			ft_printf("%s", prompt[i++]);
			if (prompt[i])
				write(1, " ", 1);
		}
	}
	if (!has_content)
		write(1, "\n", 1);
}

void	execute_builtin(char **prompt, int size)
{
	g_env->status = 0;
	if (!ft_strcmp(prompt[0], "echo"))
		execute_echo(prompt);
	if (!ft_strcmp(prompt[0], "pwd"))
		print_pwd();
	if (!ft_strcmp(prompt[0], "unset"))
		unset_env(prompt);
	if (!ft_strcmp(prompt[0], "cd"))
		change_directory(prompt);
	if (!ft_strcmp(prompt[0], "export"))
		export_env(prompt);
	if (!ft_strcmp(prompt[0], "exit"))
		exit_command(prompt, size);
	if (!ft_strcmp(prompt[0], "env"))
		print_env(prompt);
}

void	exit_command(char **prompt, int size)
{
	int	i;

	if (size == 1)
		write(1, "exit\n", 5);
	if (prompt[1])
	{
		i = -1;
		while (prompt[1][++i])
		{
			if (!ft_isdigit(prompt[1][i]))
				syntax_error("exit: numeric argument required", 255, 1);
		}
		if (prompt[1] && prompt[2])
		{
			syntax_error("exit: too many arguments", 1, 0);
			return ;
		}
		exit(ft_atoi(prompt[1]));
	}
	exit(0);
}

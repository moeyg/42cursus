/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:49:10 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:28:36 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setup_execute(t_cmd_line *cmd_line)
{
	pid_t	pid;
	int		fd[2];
	int		i;

	i = -1;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (parse_builtin(cmd_line->cmd->input) && cmd_line->size == 1)
		return (setup_builtin(cmd_line));
	while (++i < cmd_line->size)
	{
		if (pipe(fd) < 0)
			print_error("pipe error", 1, 1);
		pid = fork();
		if (pid == -1)
			print_error("fork error", 1, 1);
		if (pid == 0)
			execute_command(cmd_line, fd, i);
		dup2(fd[0], STDIN_FILENO);
		close_fd(fd[0], fd[1]);
	}
	backup_std_io(cmd_line);
	return (wait_processes(pid));
}

void	execute_command(t_cmd_line *cmd_line, int *fd, int i)
{
	char	**cmd;
	char	*execute_path;
	char	**path;

	setup_io_redirection(cmd_line, fd, i);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	path = retrieve_path();
	cmd = extract_path(cmd_line, i);
	if (!cmd)
		exit(0);
	if (parse_builtin(cmd[0]))
	{
		execute_builtin(cmd, cmd_line->size);
		exit(g_env->status);
	}
	execute_path = executable_path(path, cmd[0]);
	if (!execute_path || !cmd[0][0])
		command_error(cmd[0], 127, 1);
	if (execve(execute_path, cmd, convert_env_arr()) == -1)
		command_error(execute_path, 126, 1);
}

char	**retrieve_path(void)
{
	t_env	*env;

	env = g_env;
	while (env)
	{
		if (!ft_strncmp(env->key, "PATH", ft_strlen(env->key)))
			break ;
		env = env->next;
	}
	if (!env)
		return (0);
	return (ft_split(env->value, ':'));
}

void	close_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

int	wait_processes(pid_t last_pid)
{
	int		status;
	pid_t	pid;

	pid = 1;
	while (pid != -1)
	{
		pid = wait(&status);
		if (pid == last_pid)
		{
			if (WIFEXITED(status))
				g_env->status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				g_env->status = WTERMSIG(status) + 128;
			if (g_env->status == 131)
				ft_putstr_fd("Quit: 3\n", 2);
		}
	}
	return (1);
}

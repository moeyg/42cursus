/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:50:24 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:57:14 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	setup_io_redirection(t_cmd_line *cmd_line, int *fd, int size)
{
	t_cmd	*tmp;
	int		heredoc_index;
	int		io;

	io = 0;
	heredoc_index = 0;
	tmp = pipe_command(cmd_line, size);
	while (tmp && tmp->type != PIPE)
	{
		if (tmp->type == REDIRECTION)
		{
			setup_input_redirection(tmp, &heredoc_index);
			setup_output_redirection(tmp, &io);
			tmp = tmp -> next;
		}
		tmp = tmp -> next;
	}
	if (fd && !io && size != cmd_line->size - 1)
		dup2(fd[1], STDOUT_FILENO);
	if (fd)
	{
		close(fd[1]);
		close(fd[0]);
	}
}

void	setup_input_redirection(t_cmd *cmd, int *i)
{
	int	fd;

	if (!ft_strncmp(cmd->input, "<<", 2))
		setup_heredoc_fd((*i)++);
	else if (!ft_strncmp(cmd->input, "<", ft_strlen(cmd->input)))
	{
		fd = open(cmd->next->input, O_RDONLY);
		if (fd == -1)
			print_error(cmd->next->input, 1, 1);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
}

void	setup_output_redirection(t_cmd *cmd, int *output)
{
	int	fd;

	if (!ft_strncmp(cmd->input, ">", ft_strlen(cmd->input)))
	{
		*output = 1;
		fd = open(cmd->next->input, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			print_error(cmd->next->input, 1, 1);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else if (!ft_strncmp(cmd->input, ">>", 2))
	{
		*output = 2;
		fd = open(cmd->next->input, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			print_error(cmd->next->input, 1, 1);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

void	setup_heredoc_fd(int i)
{
	char	*filename;
	int		fd;

	filename = parse_filename(i);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error(filename, 1, 1);
	dup2(fd, STDIN_FILENO);
	free(filename);
	close(fd);
}

void	backup_std_io(t_cmd_line *cmd_line)
{
	dup2(cmd_line->input, STDIN_FILENO);
	dup2(cmd_line->output, STDOUT_FILENO);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:49:02 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:56:45 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	setup_heredoc(char *prompt)
{
	pid_t	pid;
	char	*limiter;
	char	*filename;
	int		file_path;
	int		i;

	i = -1;
	file_path = 0;
	signal(SIGINT, SIG_IGN);
	while (prompt[++i])
	{
		if (!ft_strncmp(prompt + i, "<<", 2))
		{
			limiter = parse_limiter(prompt + i + 2, &i);
			if (!limiter)
				return (1);
			pid = fork();
			filename = parse_filename(file_path++);
			if (pid == 0)
				write_heredoc(limiter, filename);
			if (!heredoc_exit(limiter, filename))
				return (0);
		}
	}
	return (1);
}

char	*parse_limiter(char *prompt, int *limiter_length)
{
	char	*limiter;
	int		length;
	int		quote;
	int		i;

	length = 0;
	while (prompt[length] && ft_isspace(prompt[length]))
		length++;
	if (!prompt[length] || command_type(prompt, length))
		return (0);
	i = 0;
	i = calc_limiter_length(prompt, length, &quote);
	if (quote < 0)
		return (0);
	limiter = extract_limiter(prompt, i, &length, quote);
	*limiter_length += length + 1;
	return (limiter);
}

char	*extract_limiter(char *prompt, int length, int *i, int quote)
{
	int		index;
	char	*limiter;

	limiter = (char *)malloc(sizeof(char) * (length + 2));
	limiter[length + 1] = '\0';
	limiter[length] = '\n';
	index = 0;
	while (prompt[*i] && !ft_isspace(prompt[*i]) && !command_type(prompt, *i))
	{
		if (prompt[*i] == '\"' || prompt[*i] == '\'')
		{
			quoted_contents(prompt + *i, &limiter, index, quote);
			*i += quote + 2;
			index += quote;
			continue ;
		}
		limiter[index] = prompt[*i];
		(*i)++;
		index++;
	}
	return (limiter);
}

void	write_heredoc(char *limiter, char *filename)
{
	char	*prompt;
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		print_error("open error", 1, 1);
	while (1)
	{
		signal(SIGINT, exit_handler);
		ft_putstr_fd("heredoc > ", 1);
		prompt = get_next_line(0);
		if (!prompt)
			break ;
		if (!ft_strncmp(prompt, limiter, ft_strlen(prompt)))
			break ;
		prompt = process_dollars(prompt);
		ft_putstr_fd(prompt, fd);
		free(prompt);
	}
	close(fd);
	if (prompt)
		free(prompt);
	free(limiter);
	free(filename);
	exit (0);
}

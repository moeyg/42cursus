/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:31:24 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/11 23:38:08 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>

# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "command.h"
# include "env.h"
# include "heredoc.h"
# include "libft.h"
# include "structure.h"

t_env	*g_env;

/* builtin.c */
int		setup_builtin(t_cmd_line *cmd_line);
int		parse_builtin(char *prompt);
void	execute_echo(char **prompt);
void	execute_builtin(char **prompt, int size);
void	exit_command(char **prompt, int size);

/* cd_utils.c */
void	change_directory(char **prompt);
void	validate_cd(char **prompt);
char	*parse_filename(int file_path);
void	print_pwd(void);

/* cd.c */
void	increment_shlvl(char *env);
int		validate_key(char *env);
int		validate_option_n(char *prompt);
void	quoted_contents(char *prompt, char **limiter, int i, int quote);
int		calc_limiter_length(char *prompt, int i, int *quote);

/* error.c */
void	command_error(char *prompt, int exit_code, int error);
void	syntax_error(char *prompt, int exit_code, int error);
void	print_error(char *prompt, int exit_code, int error);

/* execution.c */
int		setup_execute(t_cmd_line *cmd_line);
void	execute_command(t_cmd_line *cmd_line, int *fd, int i);
char	**retrieve_path(void);
void	close_fd(int fd1, int fd2);
int		wait_processes(pid_t last_pid);

/* free.c */
void	clear_prompt(t_cmd_line *line);
void	free_inputs(char *input1, char *input2, char *input3);
void	free_command(char **prompt);

/* initialize.c */
void	init(int argc, char *argv[], char *envp[], t_cmd_line *cmd_line);
int		setup_command(t_cmd_line cmd_line, char *prompt);
void	exit_minishell(void);

/* io_redirection.c */
void	setup_io_redirection(t_cmd_line *cmd_line, int *fd, int size);
void	setup_input_redirection(t_cmd *cmd, int *i);
void	setup_output_redirection(t_cmd *cmd, int *output);
void	setup_heredoc_fd(int i);
void	backup_std_io(t_cmd_line *cmd_line);

/* merge.c */
void	merge_commands(t_cmd **cmd, char *prompt);
void	merge_quotes(t_cmd_line *cmd_line);
void	tokenize(t_cmd_line *cmd_line, char *prompt);
int		parse_prompt(t_cmd_line *cmd_line, char *prompt);

/* quote.c */
void	seperate_quote(t_cmd_line *line, char *prompt);
int		process_double_quote(t_cmd_line *line, char *prompt);
int		process_single_quote(t_cmd_line *line, char *prompt);
int		process_prompt(t_cmd_line *line, char *prompt);

/* signal.c */
void	initialize_signal(void);
void	sigint_handler(int signum);
void	exit_handler(int signum);

/* space.c */
void	process_preceding_spaces(t_cmd_line *line, t_cmd **cmd, char *prompt);
void	split_command_space(t_cmd **cmd, char *prompt);
int		validate_space(char *prompt);
void	seperate_space(t_cmd_line *cmd_line);
int		is_space(char *command);

/* type.c */
void	setup_command_type(t_cmd_line *cmd_line);
void	identify_type(t_cmd **cmd, char *prompt, int size, int i);

#endif

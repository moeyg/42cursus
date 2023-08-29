/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:32:30 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/11 23:43:35 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "structure.h"

/* command_execution.c */
char	**extract_path(t_cmd_line *cmd_line, int index);
t_cmd	*pipe_command(t_cmd_line *cmd_line, int index);
char	*executable_path(char **search_path, char *cmd);

/* command_management.c */
t_cmd	*create_command(void);
t_cmd	*append_command(t_cmd_line *cmd_line);
void	delete_command(t_cmd_line *cmd_line, t_cmd **cmd);
t_cmd	*split_command(t_cmd **cmd);

/* command.c */
void	dollar_in_command(t_cmd_line *cmd_line);
int		command_type(char *prompt, int i);
int		validate_cmd_syntax(t_cmd_line *cmd_line);
int		quote_balanced(char *prompt);
int		find_closing_quote(char *prompt);

#endif

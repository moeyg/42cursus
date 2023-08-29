/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:32:41 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/10 03:33:55 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# define NO_QUOTE 		0
# define SINGLE_QUOTE	1
# define DOUBLE_QUOTE	2

typedef enum e_type
{
	CMD,
	REDIRECTION,
	PIPE
}	t_type;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				status;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	char			*input;
	int				type;
	int				quote;
	int				dollar;
	int				status;
	int				pipe;
	int				space;
	int				heredoc;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_line
{
	t_cmd	*cmd;
	int		size;
	char	**env;
	int		input;
	int		output;
	int		syntax;
}	t_cmd_line;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:04:22 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:28:29 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	struct termios	terminal;
	t_cmd_line		cmd_line;
	char			*prompt;

	tcgetattr(STDIN_FILENO, &terminal);
	init(argc, argv, envp, &cmd_line);
	while (1)
	{
		initialize_signal();
		prompt = readline("minishell $ ");
		if (!prompt)
			exit_minishell();
		if (*prompt != '\0')
			add_history(prompt);
		if (*prompt != '\0' && !is_space(prompt))
		{
			if (!setup_command(cmd_line, prompt))
			{
				free(prompt);
				continue ;
			}
		}
		free(prompt);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:04:12 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:56:35 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*process_dollars(char *prompt)
{
	int		dollar_count;
	char	*result;

	dollar_count = count_dollars(prompt);
	if (dollar_count == 0)
		return (prompt);
	result = convert_dollars(prompt, dollar_count);
	return (result);
}

int	heredoc_exit(char *limiter, char *filename)
{
	int	status;

	free(filename);
	free(limiter);
	wait(&status);
	g_env->status = WEXITSTATUS(status);
	if (g_env->status == 130)
	{
		g_env->status = 1;
		return (0);
	}
	return (1);
}

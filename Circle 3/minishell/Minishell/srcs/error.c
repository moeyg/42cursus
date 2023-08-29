/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:49:13 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:56:07 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_error(char *prompt, int exit_code, int error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(prompt, 2);
	ft_putstr_fd(": command not found\n", 2);
	if (!error)
		g_env->status = exit_code;
	if (error)
		exit(exit_code);
}

void	syntax_error(char *prompt, int exit_code, int error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(prompt, 2);
	ft_putstr_fd("\n", 2);
	if (!error)
		g_env->status = exit_code;
	if (error)
		exit(exit_code);
}

void	print_error(char *prompt, int exit_code, int error)
{
	ft_putstr_fd("minishell: ", 2);
	perror(prompt);
	if (!error)
		g_env->status = exit_code;
	if (error)
		exit(exit_code);
}

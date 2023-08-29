/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:10:44 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:55:11 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increment_shlvl(char *env)
{
	t_env	*last_env;
	char	*shlvl;

	last_env = g_env;
	while (last_env->next)
	{
		last_env = last_env->next;
	}
	last_env->next = (t_env *)malloc(sizeof(t_env));
	if (!last_env->next)
	{
		print_error("allocated error", 1, 1);
	}
	last_env = last_env->next;
	last_env->key = env_key(env);
	shlvl = env_value(env);
	last_env->value = ft_itoa(ft_atoi(shlvl) + 1);
	free(shlvl);
	last_env->next = NULL;
}

int	validate_key(char *env)
{
	char	*key;
	int		i;

	key = env_key(env);
	i = 0;
	while (key[++i])
	{
		if (!ft_isalnum(key[i]))
		{
			free(key);
			return (0);
		}
	}
	free(key);
	return (1);
}

int	validate_option_n(char *prompt)
{
	int	i;

	i = 1;
	if (prompt[0] != '-')
		return (0);
	while (prompt[i])
	{
		if (prompt[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	quoted_contents(char *prompt, char **limiter, int i, int quote)
{
	int	index;

	index = 1;
	while (index < quote + 1)
	{
		(*limiter)[i] = prompt[index];
		index++;
		i++;
	}
}

int	calc_limiter_length(char *prompt, int i, int *quote)
{
	int	length;

	length = 0;
	while (prompt[i] && !ft_isspace(prompt[i]) && !command_type(prompt, i))
	{
		if (prompt[i] == '\"' || prompt[i] == '\'')
		{
			*quote = find_closing_quote(prompt + i);
			i += *quote + 2;
			length += *quote;
			continue ;
		}
		i++;
		length++;
	}
	return (length);
}

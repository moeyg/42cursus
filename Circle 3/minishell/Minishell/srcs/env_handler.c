/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:03:55 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:55:49 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_dollars(char *prompt, int dollar_count)
{
	char	*converted;
	int		converted_count;
	int		i;

	i = 0;
	converted_count = 0;
	converted = prompt;
	while (converted_count < dollar_count)
	{
		while (converted[i] && converted[i] != '$')
			i++;
		if (converted[i] && ft_isalpha(converted[i + 1]))
		{
			converted_count++;
			converted = convert_env(prompt, &i);
		}
		else if (converted[i] && (converted[i + 1] == '?'))
		{
			converted_count++;
			converted = exit_status(converted, &i);
		}
		else
			i++;
	}
	return (converted);
}

char	*convert_env(char *prompt, int *i)
{
	t_env	*env;
	char	*converted;
	char	*buffer;
	char	*key;
	int		key_length;

	key_length = 1;
	while (prompt[*i + key_length] && ft_isalnum(prompt[*i + key_length]))
		key_length++;
	key = ft_substr(prompt, *i + 1, key_length - 1);
	env = find_env_variable(key);
	free(key);
	converted = ft_substr(prompt, 0, *i);
	if (env)
	{
		key = converted;
		converted = ft_strjoin(key, env->value);
		free(key);
	}
	key = ft_strdup(prompt + *i + key_length);
	buffer = converted;
	converted = ft_strjoin(converted, key);
	free_inputs(buffer, key, prompt);
	*i += calc_env_length(env);
	return (converted);
}

int	calc_env_length(t_env *env)
{
	int	length;

	length = 0;
	if (env)
	{
		length = ft_strlen(env->value);
	}
	return (length);
}

char	*exit_status(char *prompt, int *i)
{
	char	*converted;
	char	*exit_status;
	char	*buffer;
	int		status_length;

	converted = ft_substr(prompt, 0, *i);
	exit_status = ft_itoa(g_env->status);
	status_length = ft_strlen(exit_status);
	buffer = converted;
	converted = ft_strjoin(converted, exit_status);
	free_inputs(buffer, exit_status, NULL);
	exit_status = ft_strdup(prompt + *i + 2);
	*i += status_length;
	buffer = converted;
	converted = ft_strjoin(converted, exit_status);
	free_inputs(buffer, exit_status, prompt);
	return (converted);
}

int	count_dollars(char *prompt)
{
	int	dollar_count;
	int	i;

	i = 0;
	dollar_count = 0;
	while (prompt[i])
	{
		while (prompt[i] && prompt[i] != '$')
			i++;
		if (prompt[i] && (ft_isalpha(prompt[i + 1]) \
			|| prompt[i + 1] == '?'))
		{
			i += 2;
			dollar_count++;
		}
		else if (prompt[i])
			i++;
	}
	return (dollar_count);
}

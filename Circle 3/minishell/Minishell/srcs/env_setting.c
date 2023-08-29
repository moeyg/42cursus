/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:49:24 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:55:54 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize_env(char **env)
{
	int	i;

	if (!g_env)
	{
		g_env = (t_env *)malloc(sizeof(t_env));
		if (!g_env)
			print_error("allocated error", 1, 1);
		g_env->key = env_key(env[0]);
		g_env->value = env_value(env[0]);
		g_env->next = NULL;
	}
	i = 0;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "SHLVL=", 6))
			increment_shlvl(env[i]);
		else
			append_env(env[i]);
	}
}

char	*env_key(char *env)
{
	int	i;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	return (ft_substr(env, 0, i));
}

char	*env_value(char *env)
{
	int	i;

	if (!ft_strchr(env, '='))
		return (0);
	i = 0;
	while (env[i] != '=')
		i++;
	return (ft_strdup(env + i + 1));
}

void	append_env(char *env)
{
	t_env	*tail_env;

	tail_env = g_env;
	while (tail_env->next)
		tail_env = tail_env->next;
	tail_env->next = (t_env *)malloc(sizeof(t_env));
	if (!tail_env->next)
		print_error("allocated error", 1, 1);
	tail_env = tail_env->next;
	tail_env->key = env_key(env);
	tail_env->value = env_value(env);
	tail_env->next = NULL;
}

t_env	*find_env_variable(char	*env)
{
	t_env	*environ;
	char	*variable;
	int		i;

	i = 0;
	environ = g_env;
	while (env[i] && env[i] != '=')
		i++;
	while (environ)
	{
		variable = environ->key;
		if (!ft_strncmp(variable, env, i))
			return (environ);
		environ = environ->next;
	}
	return (0);
}

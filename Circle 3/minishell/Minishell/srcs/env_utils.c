/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:42:59 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/12 01:55:57 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export_env(char	**prompt)
{
	t_env	*env;
	int		i;

	if (!prompt[1])
	{
		print_export();
		return ;
	}
	i = 0;
	while (prompt[++i])
	{
		if (!ft_isalpha(prompt[i][0]) || !validate_key(prompt[i]))
			syntax_error("not a valid identifier", 1, 0);
		else if (find_env_variable(prompt[i]) && ft_strchr(prompt[i], '='))
		{
			env = find_env_variable(prompt[i]);
			if (env->value)
				free(env->value);
			env->value = env_value(prompt[i]);
		}
		else if (!find_env_variable(prompt[i]))
			append_env(prompt[i]);
	}
}

void	print_env(char **prompt)
{
	t_env	*env;

	if (prompt[1])
		return (print_error("Invalid argument.\n", 1, 0));
	env = g_env;
	while (env)
	{
		if (env->value)
			ft_printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

void	print_export(void)
{
	t_env	*env;

	env = g_env;
	while (env)
	{
		if (env->value)
			ft_printf("declare -x %s=\"%s\"\n", env->key, env->value);
		else
			ft_printf("declare -x %s\n", env->key);
		env = env->next;
	}
}

void	unset_env(char **prompt)
{
	t_env	*env;
	int		i;

	i = 0;
	while (prompt[++i])
	{
		if (!ft_isalpha(prompt[i][0]) || !validate_key(prompt[i]))
			syntax_error("not a valid identifier", 1, 0);
		env = find_env_variable(prompt[i]);
		if (env)
			delete_env(env);
	}
}

void	delete_env(t_env *delete)
{
	t_env	*env;

	env = g_env;
	if (delete == env)
	{
		g_env = g_env->next;
		free (delete->key);
		if (delete->value)
			free(delete->value);
		free(delete);
		return ;
	}
	env = g_env;
	while (env->next != delete)
		env = env->next;
	env->next = delete->next;
	free(delete->key);
	if (delete->value)
		free(delete->value);
	free(delete);
}

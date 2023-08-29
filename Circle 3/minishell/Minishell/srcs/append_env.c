/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:38:17 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:28:49 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**convert_env_arr(void)
{
	t_env	*current_env;
	char	**env_arr;
	char	*formatted;
	int		size;

	env_arr = 0;
	current_env = g_env;
	size = 0;
	while (current_env)
	{
		if (current_env->value)
		{
			formatted = format_env_string(current_env->key, current_env->value);
			env_arr = append_env_array(env_arr, formatted, ++size);
		}
		current_env = current_env->next;
	}
	return (env_arr);
}

char	*format_env_string(char *key, char *value)
{
	char	*formatted;
	int		key_length;
	int		value_len;
	int		i;

	key_length = ft_strlen(key);
	value_len = ft_strlen(value);
	formatted = \
		(char *)malloc(sizeof(char) * (key_length + value_len + 2));
	if (!formatted)
		print_error("allocated error", 1, 1);
	i = -1;
	while (++i < key_length)
		formatted[i] = key[i];
	formatted[i] = '=';
	i = -1;
	while (++i < value_len)
		formatted[key_length + i + 1] = value[i];
	formatted[key_length + i + 1] = 0;
	return (formatted);
}

char	**append_env_array(char **env_arr, char *env, int arr_length)
{
	char	**append;
	int		i;

	append = (char **)malloc(sizeof(char *) * (arr_length + 1));
	if (!append)
		print_error("allocated error", 1, 1);
	append[arr_length] = 0;
	i = -1;
	while (++i < arr_length - 1)
		append[i] = env_arr[i];
	append[i] = env;
	if (env_arr)
		free(env_arr);
	return (append);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:15:22 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/11 23:42:37 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/* append_env.c */
char	**convert_env_arr(void);
char	*format_env_string(char *key, char *value);
char	**append_env_array(char **env_arr, char *env, int arr_length);

/* env_handler.c */
char	*convert_dollars(char *prompt, int dollar_count);
char	*convert_env(char *prompt, int *i);
int		calc_env_length(t_env *env);
char	*exit_status(char *prompt, int *i);
int		count_dollars(char *prompt);

/* env_setting.c */
void	initialize_env(char **env);
char	*env_key(char *env);
char	*env_value(char *env);
void	append_env(char *env);
t_env	*find_env_variable(char	*env);

/* env_utils.c */
void	export_env(char	**prompt);
void	print_env(char **prompt);
void	print_export(void);
void	unset_env(char **prompt);
void	delete_env(t_env *delete);

#endif

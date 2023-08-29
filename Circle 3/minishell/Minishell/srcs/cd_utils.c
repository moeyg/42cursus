/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:42:15 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/29 21:28:53 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_directory(char **prompt)
{
	t_env	*old_pwd;
	char	*old_pwd_value;
	char	*pwd_value;

	validate_cd(prompt);
	pwd_value = getcwd(NULL, 0);
	old_pwd = find_env_variable("OLDPWD");
	if (old_pwd)
	{
		free(old_pwd->value);
		old_pwd->value = pwd_value;
	}
	else
	{
		old_pwd_value = ft_strjoin("OLDPWD=", pwd_value);
		append_env(old_pwd_value);
		free(old_pwd_value);
		free(pwd_value);
	}
}

void	validate_cd(char **prompt)
{
	t_env	*home;
	int		cd;

	if (!prompt[1])
	{
		home = find_env_variable("HOME");
		if (home)
			cd = chdir(home->value);
		else
			syntax_error("Home not set", 1, 0);
	}
	else
	{
		cd = chdir(prompt[1]);
		if (cd == -1)
			print_error(prompt[0], 1, 0);
	}
}

char	*parse_filename(int file_path)
{
	char	*filename;
	char	*path;

	path = ft_itoa(file_path);
	filename = ft_strjoin("/tmp/.heredoc/", path);
	free(path);
	return (filename);
}

void	print_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_printf("%s\n", pwd);
	free(pwd);
}

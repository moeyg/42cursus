/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:06:33 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 19:54:12 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_extention(char *file, char *extension)
{
	int	filename_length;

	filename_length = ft_strlen(file);
	if (!ft_strncmp(file + filename_length - 4, extension, 4))
	{
		return (TRUE);
	}
	else
	{
		return (FALSE);
	}
}

int	valid_components(char *components, char component)
{
	int	i;

	i = -1;
	while (components[++i])
	{
		if (components[i] == component)
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

void	valid_environment(t_game *game)
{
	if (!game->textures[1].texture_path || \
		!valid_extention(game->textures[1].texture_path, XPM_EXTENSION))
	{
		exit_program("Invalid north.xpm file.");
	}
	if (!game->textures[2].texture_path || \
		!valid_extention(game->textures[2].texture_path, XPM_EXTENSION))
	{
		exit_program("Invalid south.xpm file.");
	}
	if (!game->textures[3].texture_path || \
		!valid_extention(game->textures[3].texture_path, XPM_EXTENSION))
	{
		exit_program("Invalid west.xpm file.");
	}
	if (!game->textures[4].texture_path || \
		!valid_extention(game->textures[4].texture_path, XPM_EXTENSION))
	{
		exit_program("Invalid east.xpm file.");
	}
	if (game->background.floor_color == INIT || \
		game->background.ceil_color == INIT || \
		game->background.floor_color == game->background.ceil_color)
		exit_program("Invalid color value.");
}

void	valid_color(char *color_info)
{
	int		rgb;
	int		value;
	char	**color;

	valid_rgb(color_info);
	color = ft_split(color_info, ',');
	if (!color)
		exit_program("Invalid RGB format.");
	rgb = -1;
	while (color[++rgb])
	{
		value = -1;
		while (color[rgb][++value])
		{
			if (!ft_isdigit(color[rgb][value]))
				exit_program("Invalid RGB format.");
		}
	}
	if (rgb != 3)
		exit_program("Invalid RGB format.");
	rgb = -1;
	while (color[++rgb])
		free(color[rgb]);
	free(color);
}

void	valid_rgb(char *rgb)
{
	int	comma_count;

	comma_count = 0;
	while (*rgb)
	{
		if (*rgb == ',')
		{
			comma_count++;
		}
		rgb++;
	}
	if (comma_count != 2)
	{
		exit_program("Invalid RGB format.");
	}
}

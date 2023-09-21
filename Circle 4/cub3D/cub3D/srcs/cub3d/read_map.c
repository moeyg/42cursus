/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:04:09 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 19:42:31 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_texture_path(char *path)
{
	char	**texture_path;
	char	*read_path;
	int		i;

	texture_path = ft_split(path, ' ');
	if (!texture_path[1] || texture_path[2])
	{
		exit_program("Invalid file path.");
	}
	read_path = ft_strdup(texture_path[1]);
	i = -1;
	while (texture_path[++i])
	{
		free(texture_path[i]);
	}
	free(texture_path);
	return (read_path);
}

int	read_color(char *map)
{
	char	*color_info;
	int		color;

	if (*map == '\0')
	{
		exit_program("Empty color information.");
	}
	color_info = read_texture_path(map);
	color = setting_color(color_info);
	return (color);
}

char	*read_map_data(t_map *map, char *map_info)
{
	char	*map_data;
	char	*temp;

	if (map->map_data == 0)
	{
		temp = ft_strdup("");
	}
	else
	{
		temp = ft_strjoin(map->map_data, "\n");
	}
	free(map->map_data);
	map_data = ft_strjoin(temp, map_info);
	free(temp);
	return (map_data);
}

int	read_xpm(char *path, t_game *game, int direction)
{
	int	xpm_fd;

	xpm_fd = open(path, O_RDONLY);
	if (xpm_fd == -1)
	{
		exit_program("Failed to open xpm file.");
	}
	close(xpm_fd);
	game->textures[direction].texture_path = ft_strdup(path);
	return (TRUE);
}

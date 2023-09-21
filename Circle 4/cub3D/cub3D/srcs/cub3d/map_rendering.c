/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:03:35 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 17:37:03 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_rendering(t_map *map)
{
	map_parsing(map);
	map_setting(map);
}

void	map_parsing(t_map *map)
{
	int	col;
	int	row;

	map->parsed_map = ft_split(map->map_data, '\n');
	if (map->parsed_map == 0)
	{
		exit_program("Failed to saved map.");
	}
	col = -1;
	row = 0;
	while (map->parsed_map[++col] != 0)
	{
		if (ft_strlen(map->parsed_map[col]) > (size_t)row)
		{
			row = ft_strlen(map->parsed_map[col]);
		}
	}
	map->cols = row;
	map->rows = col;
	free(map->map_data);
	map->map_data = NULL;
}

void	map_setting(t_map *map)
{
	int	col;
	int	row;

	col = -1;
	while (map->parsed_map[++col])
	{
		row = -1;
		while (map->parsed_map[col][++row])
		{
			if (ft_strchr(UNMOVABLE, map->parsed_map[col][row]))
				continue ;
			else if (ft_strchr(MOVABLE, map->parsed_map[col][row]))
			{
				if (setting_components(map, col, row) == ERROR)
				{
					exit_program("Invalid map components.");
				}
			}
		}
	}
	if (!map->player.initial_direction)
		exit_program("Failed to save the player's position.");
}

int	setting_components(t_map *map, int col, int row)
{
	if (row == 0 \
		|| col == 0 \
		|| row == (int)ft_strlen(map->parsed_map[col]) - 1 \
		|| col == map->rows - 1)
		return (-1);
	if (map->parsed_map[col][row + 1] == ' ' \
		|| map->parsed_map[col][row - 1] == ' ')
		return (-1);
	if ((int)ft_strlen(map->parsed_map[col - 1]) <= row \
		|| map->parsed_map[col - 1][row] == ' ' \
		|| map->parsed_map[col - 1][row] == '\0')
		return (-1);
	if ((int)ft_strlen(map->parsed_map[col + 1]) <= row \
		|| map->parsed_map[col + 1][row] == ' ' \
		|| map->parsed_map[col + 1][row] == '\0')
		return (-1);
	if (map->parsed_map[col][row] != '0')
	{
		player_position(map, col, row);
	}
	return (1);
}

void	player_position(t_map *map, int col, int row)
{
	if (map->player.initial_direction || map->player.y || map->player.x)
	{
		exit_program("Duplicated player position.");
	}
	map->player.initial_direction = map->parsed_map[col][row];
	map->player.y = (double)col;
	map->player.x = (double)row;
	map->parsed_map[col][row] = '0';
}

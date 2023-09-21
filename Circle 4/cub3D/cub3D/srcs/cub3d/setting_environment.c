#include "cub3d.h"

void	setting_environment(t_game *game, int map_info, char *map)
{
	if (NO <= map_info && map_info <= EA)
	{
		setting_texture_path(game, map_info, map);
	}
	else if (F <= map_info && map_info <= C)
	{
		setting_background(&game->background, map_info, map);
	}
	else
	{
		setting_map(&game->map, game, map);
	}
}

void	setting_texture_path(t_game *game, int map_info, char *map)
{
	char	*path;

	path = read_texture_path(map);
	if (map_info == NO \
		&& (game->textures[NO].texture_path || !read_xpm(path, game, NO)))
	{
		exit_program("Invalid 'NO' file.");
	}
	else if (map_info == SO \
		&& (game->textures[SO].texture_path || !read_xpm(path, game, SO)))
	{
		exit_program("Invalid 'SO' file.");
	}
	else if (map_info == WE \
		&& (game->textures[WE].texture_path || !read_xpm(path, game, WE)))
	{
		exit_program("Invalid 'WE' file.");
	}
	else if (map_info == EA \
		&& (game->textures[EA].texture_path || !read_xpm(path, game, EA)))
	{
		exit_program("Invalid 'EA' file.");
	}
	free(path);
}

void	setting_background(t_background *background, int map_info, char *map)
{
	if (map_info == F)
	{
		if (background->floor_color != INIT)
		{
			exit_program("Already set the Floor color.");
		}
		background->floor_color = read_color(map);
	}
	else if (map_info == C)
	{
		if (background->ceil_color != INIT)
		{
			exit_program("Already set the Ceiling color.");
		}
		background->ceil_color = read_color(map);
	}
}

void	setting_map(t_map *map, t_game *game, char *map_info)
{
	valid_environment(game);
	map->map_data = read_map_data(map, map_info);
}

#include "cub3d.h"

void	free_program(t_game *game, char *message)
{
	print_error(message);
	free_datas(game, 0);
	exit(FAIL);
}

void	free_datas(t_game *game, int i)
{
	while (++i <= 4)
	{
		if (game->textures[i].texture_path)
		{
			free(game->textures[i].texture_path);
			game->textures[i].texture_path = NULL;
			free(game->textures[i].data);
			game->textures[i].data = NULL;
		}
	}
	if (game->map.map_data)
		free(game->map.map_data);
	game->map.map_data = NULL;
	if (game->map.parsed_map)
	{
		i = -1;
		while (game->map.parsed_map[++i])
		{
			free(game->map.parsed_map[i]);
			game->map.parsed_map[i] = NULL;
		}
		free(game->map.parsed_map);
	}
}

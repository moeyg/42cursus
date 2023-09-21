#include "cub3d.h"

void	initialize_raycasting(t_game *game, int x)
{
	game->camera = 2 * x / (double)(SCREEN_WIDTH - 1) - 1;
	game->raycasting_x \
		= game->direction_x + game->angle_x * game->camera;
	game->raycasting_y \
		= game->direction_y + game->angle_y * game->camera;
	game->map_x = (int)(game->player_x);
	game->map_y = (int)(game->player_y);
	calculate_delta_distances(game);
	calculate_side_distances(game);
	game->hit = 0;
}

void	calculate_delta_distances(t_game *game)
{
	if (game->raycasting_y == 0)
	{
		game->delta_x = 0;
	}
	else if (game->raycasting_x == 0)
	{
		game->delta_x = 1;
	}
	else
	{
		game->delta_x = fabs(1 / game->raycasting_x);
	}
	if (game->raycasting_x == 0)
	{
		game->delta_y = 0;
	}
	else if (game->raycasting_y == 0)
	{
		game->delta_y = 1;
	}
	else
	{
		game->delta_y = fabs(1 / game->raycasting_y);
	}
}

void	calculate_side_distances(t_game *game)
{
	if (game->raycasting_x < 0)
	{
		game->step_x = -1;
		game->distance_x = (game->player_x - game->map_x) * game->delta_x;
	}
	else
	{
		game->step_x = 1;
		game->distance_x = (game->map_x + 1.0 - game->player_x) * game->delta_x;
	}
	if (game->raycasting_y < 0)
	{
		game->step_y = -1;
		game->distance_y = (game->player_y - game->map_y) * game->delta_y;
	}
	else
	{
		game->step_y = 1;
		game->distance_y = (game->map_y + 1.0 - game->player_y) * game->delta_y;
	}
}

#include "cub3d.h"

void	calculate_colliision(t_game *game)
{
	while (game->hit == 0)
	{
		if (game->distance_x < game->distance_y)
		{
			game->distance_x += game->delta_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->distance_y += game->delta_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->map.parsed_map[game->map_x][game->map_y] > '0')
			game->hit = 1;
	}
	if (game->side == 0)
		game->vert_distance = \
			(game->map_x - game->player_x + (1 - game->step_x) / 2) \
			/ game->raycasting_x;
	else
		game->vert_distance = \
			(game->map_y - game->player_y + (1 - game->step_y) / 2) \
			/ game->raycasting_y;
}

void	calculate_draw(t_game *game)
{
	game->line_height = (int)(SCREEN_HEIGHT / game->vert_distance);
	game->rendering_start = (-1 * game->line_height / 2) + (SCREEN_HEIGHT / 2);
	if (game->rendering_start < 0)
	{
		game->rendering_start = 0;
	}
	game->redering_end = game->line_height / 2 + SCREEN_HEIGHT / 2;
	if (game->redering_end >= SCREEN_HEIGHT)
	{
		game->redering_end = SCREEN_HEIGHT - 1;
	}
}

t_texture	setting_texture(t_game *game)
{
	t_texture	texture;

	if (game->side == 0)
	{
		if (game->step_x == -1)
		{
			texture = game->textures[WE];
		}
		else
		{
			texture = game->textures[EA];
		}
	}
	else
	{
		if (game->step_y == -1)
		{
			texture = game->textures[NO];
		}
		else
		{
			texture = game->textures[SO];
		}
	}
	return (texture);
}

void	calculate_wall(t_game *game, t_texture texture)
{
	if (game->side == 0)
	{
		game->wall_direction = \
			game->player_y + game->vert_distance * game->raycasting_y;
	}
	else
	{
		game->wall_direction = \
			game->player_x + game->vert_distance * game->raycasting_x;
	}
	game->wall_direction -= floor((game->wall_direction));
	game->texture_x = (int)(game->wall_direction * (double)(texture.width));
	if (game->side == 0 && game->raycasting_x > 0)
	{
		game->texture_x = texture.width - game->texture_x - 1;
	}
	if (game->side == 1 && game->raycasting_y < 0)
	{
		game->texture_x = texture.width - game->texture_x - 1;
	}
	game->step = 1.0 * texture.height / game->line_height;
	game->texture_position = \
		(game->rendering_start - SCREEN_HEIGHT / 2 + game->line_height / 2);
	game->texture_position *= game->step;
}

void	redering_wall(t_game *game, t_texture texture, int x)
{
	int	y;
	int	color;

	y = game->rendering_start - 1;
	while (++y < game->redering_end)
	{
		game->texture_y = (int)(game->texture_position) & (texture.height - 1);
		game->texture_position += game->step;
		color = \
			game->wall_data[texture.height * game->texture_y + game->texture_x];
		if (game->side == 1)
		{
			color = (color >> 1) & 8355711;
		}
		game->screen_data[y * SCREEN_WIDTH + x] = color;
	}
}

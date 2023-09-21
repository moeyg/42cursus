#include "cub3d.h"

void	raycasting(t_game *game, int x)
{
	t_texture	wall;

	initialize_raycasting(game, x);
	calculate_colliision(game);
	calculate_draw(game);
	wall = setting_texture(game);
	game->wall_data = \
		(unsigned int *)mlx_get_data_addr(wall.texture.img, \
		&(wall.texture.bpp), \
		&(wall.texture.line_size), \
		&(wall.texture.endian));
	calculate_wall(game, wall);
	redering_wall(game, wall, x);
}

int	redering_frame(t_game *game)
{
	int	width;

	mlx_clear_window(game->mlx, game->window);
	game->screen_data = \
		(unsigned int *)mlx_get_data_addr(game->screen.img, \
		&(game->screen.bpp), \
		&(game->screen.line_size), \
		&(game->screen.endian));
	setting_frame(game);
	width = -1;
	while (++width < SCREEN_WIDTH)
	{
		raycasting(game, width);
	}
	mlx_put_image_to_window(game->mlx, game->window, game->screen.img, 0, 0);
	return (0);
}

void	setting_frame(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
			{
				game->screen_data[y * SCREEN_WIDTH + x] \
					= game->background.ceil_color;
			}
			else if (y > SCREEN_HEIGHT / 2)
			{
				game->screen_data[y * SCREEN_WIDTH + x] \
					= game->background.floor_color;
			}
			else
				game->screen_data[y * SCREEN_WIDTH + x] = 0;
		}
	}
}

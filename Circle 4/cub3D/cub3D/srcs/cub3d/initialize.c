/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:03:24 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 19:35:08 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_game(t_game *game, int map_fd)
{
	char	*map;
	int		map_info;

	ft_memset(game, 0, sizeof(t_game));
	game->background.floor_color = INIT;
	game->background.ceil_color = INIT;
	map = get_next_line(map_fd);
	while (map != NULL)
	{
		map[ft_strlen(map) - 1] = '\0';
		if (map[0] != '\0')
		{
			map_info = parse_map(map);
			if (!map_info)
				exit_program("Invalid map information.");
			setting_environment(game, map_info, map);
		}
		free(map);
		map = get_next_line(map_fd);
	}
	map_rendering(&game->map);
	close(map_fd);
	free(map);
}

void	initialize_coordinates(t_game *game)
{
	double	angle;

	game->player_x = game->map.player.y + 0.5f;
	game->player_y = game->map.player.x + 0.5f;
	if (game->map.player.initial_direction == 'N')
	{
		angle = M_PI;
	}
	else if (game->map.player.initial_direction == 'E')
	{
		angle = M_PI_2;
	}
	else if (game->map.player.initial_direction == 'S')
	{
		angle = 0;
	}
	else
		angle = -M_PI_2;
	game->direction_x = cos(angle);
	game->direction_y = sin(angle);
	game->angle_x = 0.66 * cos(angle - M_PI_2);
	game->angle_y = 0.66 * sin(angle - M_PI_2);
}

int	initialize_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		return (1);
	}
	game->window = mlx_new_window \
		(game->mlx, (int)SCREEN_WIDTH, (int)SCREEN_HEIGHT, "CUB_3D");
	if (!game->window)
	{
		return (1);
	}
	return (0);
}

void	initialize_texture(t_game *game)
{
	t_texture	*texture;

	texture = game->textures;
	texture[1].texture.img = mlx_xpm_file_to_image \
		(game->mlx, texture[1].texture_path, \
		&(texture[1].width), &(texture[1].height));
	texture[2].texture.img = mlx_xpm_file_to_image \
		(game->mlx, texture[2].texture_path, \
		&(texture[2].width), &(texture[2].height));
	texture[3].texture.img = mlx_xpm_file_to_image \
		(game->mlx, texture[3].texture_path, \
		&(texture[3].width), &(texture[3].height));
	texture[4].texture.img = mlx_xpm_file_to_image \
		(game->mlx, texture[4].texture_path, \
		&(texture[4].width), &(texture[4].height));
	game->screen.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:04:30 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 19:37:25 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	press_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, 0);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, M_PI);
	else if (key == KEY_A)
		move_player(game, M_PI_2);
	else if (key == KEY_D)
		move_player(game, -M_PI_2);
	else if (key == KEY_RIGHT)
		player_angle(game, -ROTATION_ANGLE * 0.1f);
	else if (key == KEY_LEFT)
		player_angle(game, ROTATION_ANGLE * 0.1f);
	return (0);
}

void	move_player(t_game *game, double angle)
{
	double	x;
	double	y;

	y = (game->player_y);
	x = (game->player_x \
		+ (game->direction_x * cos(angle) - game->direction_y * sin(angle)) \
		* FPS);
	if (valid_position(game, x, y))
	{
		game->player_x = x;
	}
	y = (game->player_y \
		+ (game->direction_x * sin(angle) + game->direction_y * cos(angle)) \
		* FPS);
	x = (game->player_x);
	if (valid_position(game, x, y))
	{
		game->player_y = y;
	}
}

int	valid_position(t_game *game, double updated_x, double updated_y)
{
	int	x;
	int	y;

	x = (int)updated_x;
	y = (int)updated_y;
	if (x < 0 || y < 0 || x >= game->map.rows || y >= game->map.cols)
	{
		return (0);
	}
	if (game->map.parsed_map[x][y] > '0')
	{
		return (0);
	}
	else
		return (1);
}

void	player_angle(t_game *game, double angle)
{
	double	updated_direction_x;
	double	updated_direction_y;
	double	updated_angle_x;
	double	updated_angle_y;

	updated_direction_x = \
		game->direction_x * cos(angle) - game->direction_y * sin(angle);
	updated_direction_y = \
		game->direction_x * sin(angle) + game->direction_y * cos(angle);
	updated_angle_x = \
		game->angle_x * cos(angle) - game->angle_y * sin(angle);
	updated_angle_y = \
		game->angle_x * sin(angle) + game->angle_y * cos(angle);
	game->direction_x = updated_direction_x;
	game->direction_y = updated_direction_y;
	game->angle_x = updated_angle_x;
	game->angle_y = updated_angle_y;
}

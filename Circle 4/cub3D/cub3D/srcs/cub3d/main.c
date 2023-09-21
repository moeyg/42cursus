/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 22:50:32 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 20:51:04 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;
	int		map;

	if (argc != 2)
	{
		exit_program("Invalid arguments.");
	}
	map = map_file(argv[1]);
	initialize_game(&game, map);
	initialize_coordinates(&game);
	initialize_window(&game);
	initialize_texture(&game);
	mlx_hook(game.window, KEY_PRESS, 0, &press_key, &game);
	mlx_hook(game.window, KEY_EXIT, 0, &exit_game, &game);
	mlx_loop_hook(game.mlx, &redering_frame, &game);
	mlx_loop(game.mlx);
	free_datas(&game, 0);
}

int	map_file(char *map_file)
{
	int	fd;

	if (!valid_extention(map_file, MAP_EXTENSION))
	{
		exit_program("Invalid extension.");
	}
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		exit_program("Failed to open file.");
	}
	return (fd);
}

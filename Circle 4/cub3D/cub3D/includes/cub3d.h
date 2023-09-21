/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:33:03 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 19:55:00 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structure.h"
# include "macro.h"
# include "../srcs/libft/libft.h"
# include "../srcs/mlx/mlx.h"

# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <stdio.h>

/* main.c */
int			map_file(char *map_file);
void		print_usage(void);

/* initialize.c */
void		initialize_game(t_game *game, int map_fd);
void		initialize_coordinates(t_game *game);
int			initialize_window(t_game *game);
void		initialize_texture(t_game *game);

/* read_map.c */
char		*read_texture_path(char *path);
int			read_color(char *map);
char		*read_map_data(t_map *map, char *map_info);
int			read_xpm(char *path, t_game *game, int direction);

/* map_parsing.c */
int			parse_map(char *map);
int			parse_direction(char *direction);
int			parse_background(char *background);
int			parse_map_component(char *components);

/* map_rendering.c */
void		map_rendering(t_map *map);
void		map_parsing(t_map *map);
void		map_setting(t_map *map);
int			setting_components(t_map *map, int col, int row);
void		player_position(t_map *map, int col, int row);

/* raycasting.c */
void		raycasting(t_game *game, int x);
int			redering_frame(t_game *game);
void		setting_frame(t_game *game);

/* initial_raycasting.c */
void		initialize_raycasting(t_game *game, int x);
void		calculate_delta_distances(t_game *game);
void		calculate_side_distances(t_game *game);

/* setting_raycasting.c */
void		calculate_colliision(t_game *game);
void		calculate_draw(t_game *game);
t_texture	setting_texture(t_game *game);
void		calculate_wall(t_game *game, t_texture texture);
void		redering_wall(t_game *game, t_texture texture, int x);

/* setting_color.c */
int			setting_color(char *color_info);
int			setting_rgb(char *color_info, int *value);

/* setting_environment.c */
void		setting_environment(t_game *game, int map_info, char *map);
void		setting_texture_path(t_game *game, int map_info, char *map);
void		setting_background(t_background *background, int map_info, char *map);
void		setting_map(t_map *map, t_game *game, char *map_info);

/* key_events.c */
int			press_key(int key, t_game *game);
void		move_player(t_game *game, double angle);
int			valid_position(t_game *game, double updated_x, double updated_y);
void		player_angle(t_game *game, double angle);

/* validate.c */
int			valid_extention(char *file, char *extension);
int			valid_components(char *components, char component);
void		valid_environment(t_game *game);
void		valid_color(char *color_info);
void		valid_rgb(char *rgb);

/* free_memory.c */
void		free_program(t_game *game, char *message);
void		free_datas(t_game *game, int i);

/* exit_cub3d.c */
int			exit_game(t_game *game);
void		exit_program(char *message);
void		print_error(char *message);

#endif

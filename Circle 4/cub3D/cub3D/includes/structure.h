#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_player
{
	char			initial_direction;
	double			y;
	double			x;
	double			direction_x;
	double			direction_y;
}	t_player;

typedef struct s_background
{
	int				ceil_color;
	int				floor_color;
}	t_background;

typedef struct s_image
{
	void			*img;
	int				bpp;
	int				endian;
	int				line_size;
	unsigned int	*pixels;
}	t_image;

typedef struct s_texture
{
	t_image			texture;
	char			*texture_path;
	int				width;
	int				height;
	unsigned int	*data;
}	t_texture;

typedef struct s_map
{
	t_player		player;
	char			**parsed_map;
	char			*map_data;
	int				rows;
	int				cols;
}	t_map;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_image			wall;
	unsigned int	*wall_data;
	t_image			screen;
	unsigned int	*screen_data;

	t_background	background;
	t_texture		textures[5];
	t_map			map;

	double			player_x;
	double			player_y;
	double			direction_x;
	double			direction_y;

	double			angle_x;
	double			angle_y;

	double			camera;
	double			raycasting_x;
	double			raycasting_y;
	double			distance_x;
	double			distance_y;
	double			delta_x;
	double			delta_y;
	double			vert_distance;
	int				hit;
	int				side;

	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				line_height;
	int				rendering_start;
	int				redering_end;

	double			wall_direction;
	int				texture_x;
	int				texture_y;
	double			step;
	double			texture_position;
}	t_game;

#endif

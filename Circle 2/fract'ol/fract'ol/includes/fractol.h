/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:10:42 by sichoi            #+#    #+#             */
/*   Updated: 2023/06/08 00:19:42 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define KEY_PRESS		2
# define KEY_RELEASE	3

# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ESC			53
# define REFRESH		15

# define NUMERIC_1		18
# define NUMERIC_2		19
# define NUMERIC_3		20

# define RED			0x00FF0000
# define GREEN			0x0000FF00
# define BLUE			0x00000FF
# define WHITE			0x00FFFFFF
# define BLACK			0x00000000

# define ZOOM_IN	5
# define ZOOM_OUT	4

# define WIDTH		1280
# define HEIGHT		720

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_fractol
{
	int			(*func)(struct s_fractol *fractol, int x, int y);
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	double		zoom;
	int			max_iter;
	t_rgb		rgb;
	int			rgb_flag;
	void		*minilibx;
	void		*window;
	void		*image;
	char		*pixel_data;
	int			row_bytes;
	int			pixel_depth;
	int			endian;
	t_complex	c;
}	t_fractol;

/* calculate_fractol.c */
int		calculate_mandelbrot(t_fractol *fractol, int x, int y);
int		calculate_julia(t_fractol *fractol, int x, int y);
int		calculate_burning_ship(t_fractol *fractol, int x, int y);

/* draw_fractol.c */
int		draw_fractol(t_fractol *fractol);

/* key_events.c */
int		press_key(int key, t_fractol *f);
void	press_numeric(int key, t_fractol *fractol);
void	press_arrow(int key, t_fractol *fractol);

/* mouse_events.c */
int		scroll_mouse(int button, int x, int y, t_fractol *f);
void	reset_scale(t_complex mouse, double scale, t_fractol *fractol);

/* utils.c */
char	*ft_itoa(int n);
int		ft_strcmp(const char *str1, const char *str2);
double	ft_strtod(const char *s);

/* setting */
void	setting_default(t_fractol *fractol);
void	redraw_fractol(t_fractol *fractol);
void	exit_program(int parameter);

#endif

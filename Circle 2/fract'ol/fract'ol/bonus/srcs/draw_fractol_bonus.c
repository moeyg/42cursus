#include "../includes/fractol_bonus.h"

static void	colorize_fractol(int pixel, t_fractol *fractol);
static int	calculate_pixel(int pixel);
static void	pixelate_fractol(t_fractol *fractol, int x, int y);
static int	inform_iteration(t_fractol *fractol);

int	draw_fractol(t_fractol *fractol)
{
	int		iter;
	int		x;
	int		y;

	fractol->factor.r = (fractol->max.r - fractol->min.r) / WIDTH;
	fractol->factor.i = (fractol->max.i - fractol->min.i) / HEIGHT;
	y = 0;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			iter = fractol->func(fractol, x, y);
			colorize_fractol(iter, fractol);
			pixelate_fractol(fractol, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->minilibx, fractol->window, \
							fractol->image, 0, 0);
	inform_iteration(fractol);
	return (0);
}

static void	colorize_fractol(int pixel, t_fractol *fractol)
{
	pixel = (double)pixel / fractol->max_iter * 100;
	if (pixel == 100)
		fractol->rgb = (t_rgb){0, 0, 0};
	else
	{
		if (fractol->rgb_flag == 1)
			fractol->rgb = (t_rgb){calculate_pixel(255 - pixel * 3), \
								calculate_pixel(255 - pixel * 2), \
								calculate_pixel(255 - pixel * 3)};
		if (fractol->rgb_flag == 2)
			fractol->rgb = (t_rgb){(pixel * 7) % 255, \
								(pixel * 3) % 4, \
								(pixel * 2) % 70};
		if (fractol->rgb_flag == 3)
			fractol->rgb = (t_rgb){calculate_pixel(255 - pixel * 7), \
								calculate_pixel(255 - pixel * 3), \
								calculate_pixel(255 - pixel * 1)};
	}
	if (pixel == 100 && fractol->rgb_flag == 3)
		fractol->rgb = (t_rgb){255, 255, 255};
}

static int	calculate_pixel(int pixel)
{
	if (pixel < 0)
		pixel = 0;
	return (pixel);
}

static void	pixelate_fractol(t_fractol *fractol, int x, int y)
{
	int	pixel;
	int	offset;

	pixel = fractol->pixel_depth / 8;
	if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
	{
		offset = (x * pixel) + (y * fractol->row_bytes);
		fractol->pixel_data[offset + 2] = fractol->rgb.red;
		fractol->pixel_data[offset + 1] = fractol->rgb.green;
		fractol->pixel_data[offset] = fractol->rgb.blue;
	}
}

static int	inform_iteration(t_fractol *fractol)
{
	char	*iteration;
	int		font;

	if (fractol->rgb_flag == 1)
	{
		font = RED;
	}
	if (fractol->rgb_flag == 2)
	{
		font = WHITE;
	}
	else
	{
		font = BLACK;
	}
	iteration = ft_itoa(fractol->max_iter);
	mlx_string_put(fractol->minilibx, fractol->window, \
				10, 10, font, "iteration: ");
	mlx_string_put(fractol->minilibx, fractol->window, \
				120, 10, font, iteration);
	free(iteration);
	return (0);
}

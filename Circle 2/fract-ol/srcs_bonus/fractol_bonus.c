#include "../includes/fractol.h"

static int	classify_fractol(char *argv[]);
static void	initialize(t_fractol *fractol, int type, char *argv[]);
static void	program_usage(void);

int	main(int argc, char *argv[])
{
	t_fractol	fractol;
	int			type;

	if (argc >= 2)
	{
		type = classify_fractol(argv);
	}
	if (argc >= 2 && type != 0)
	{
		initialize(&fractol, type, argv);
		if (draw_fractol(&fractol) == -1)
		{
			write(1, "Failed to draw fractol.\n", 24);
			exit(-1);
		}
		mlx_hook(fractol.window, KEY_PRESS, 0, press_key, &fractol);
		mlx_hook(fractol.window, 17, 0, 0, 0);
		mlx_mouse_hook(fractol.window, scroll_mouse, &fractol);
		mlx_loop(fractol.minilibx);
	}
	else
	{
		program_usage();
	}
	return (0);
}

static int	classify_fractol(char *argv[])
{
	char	*fractol;

	fractol = argv[1];
	if (ft_strcmp(fractol, "mandelbrot") == 0)
	{
		return (1);
	}
	if (ft_strcmp(fractol, "burning_ship") == 0)
	{
		return (3);
	}
	if (ft_strcmp(fractol, "julia") == 0)
	{
		if (argv[2] == 0 || argv[3] == 0)
		{
			program_usage();
			return (0);
		}
		return (2);
	}
	return (0);
}

static void	initialize(t_fractol *fractol, int type, char *argv[])
{
	char	*fractol_type;

	fractol_type = argv[1];
	fractol->minilibx = mlx_init();
	fractol->window = \
				mlx_new_window(fractol->minilibx, WIDTH, HEIGHT, fractol_type);
	fractol->image = mlx_new_image(fractol->minilibx, WIDTH, HEIGHT);
	fractol->pixel_data = \
				mlx_get_data_addr(fractol->image, &fractol->pixel_depth, \
								&fractol->row_bytes, &fractol->endian);
	setting_default(fractol);
	if (type == 1)
	{
		fractol->func = calculate_mandelbrot;
	}
	if (type == 3)
	{
		fractol->func = calculate_burning_ship;
	}
	if (type == 2)
	{
		fractol->c.r = ft_strtod(argv[2]);
		fractol->c.i = ft_strtod(argv[3]);
		fractol->func = calculate_julia;
	}
}

static void	program_usage(void)
{
	write(1, "Fractol List\n", 13);
	write(1, "∙ mandelbrot   (Usage: ./fractol mandelbrot)\n", 47);
	write(1, "∙ juilia       (Usage: ./fractol julia c c)\n", 46);
	write(1, "∙ burning_ship (Usage: ./fractol burning_ship)\n", 49);
}

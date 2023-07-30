#include "../includes/fractol_bonus.h"

void	setting_default(t_fractol *fractol)
{
	fractol->max_iter = 50;
	fractol->min.r = -2.5;
	fractol->max.r = 1.0;
	fractol->min.i = -1.0;
	fractol->max.i = 1.0;
	fractol->zoom = 1.0;
	fractol->rgb_flag = 1;
}

void	redraw_fractol(t_fractol *fractol)
{
	mlx_clear_window(fractol->minilibx, fractol->window);
	if (draw_fractol(fractol) == -1)
	{
		exit_program(1);
	}
}

void	exit_program(int parameter)
{
	exit(parameter);
}

#include "../includes/fractol_bonus.h"

int	press_key(int key, t_fractol *fractol)
{
	if (key == ESC)
	{
		exit_program(0);
	}
	if (key == NUMERIC_1 || key == NUMERIC_2 || key == NUMERIC_3)
	{
		press_numeric(key, fractol);
	}
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
	{
		press_arrow(key, fractol);
	}
	else if (key == REFRESH)
	{
		setting_default(fractol);
		redraw_fractol(fractol);
	}
	return (0);
}

void	press_numeric(int key, t_fractol *fractol)
{
	if (key == NUMERIC_1)
	{
		fractol->rgb_flag = 1;
	}
	if (key == NUMERIC_2)
	{
		fractol->rgb_flag = 2;
	}
	if (key == NUMERIC_3)
	{
		fractol->rgb_flag = 3;
	}
	redraw_fractol(fractol);
}

void	press_arrow(int key, t_fractol *fractol)
{
	if (key == UP)
	{
		fractol->min.i -= 0.1 * fractol->zoom;
		fractol->max.i -= 0.1 * fractol->zoom;
	}
	if (key == DOWN)
	{
		fractol->min.i += 0.1 * fractol->zoom;
		fractol->max.i += 0.1 * fractol->zoom;
	}
	if (key == RIGHT)
	{
		fractol->min.r += 0.1 * fractol->zoom;
		fractol->max.r += 0.1 * fractol->zoom;
	}
	if (key == LEFT)
	{
		fractol->min.r -= 0.1 * fractol->zoom;
		fractol->max.r -= 0.1 * fractol->zoom;
	}
	redraw_fractol(fractol);
}

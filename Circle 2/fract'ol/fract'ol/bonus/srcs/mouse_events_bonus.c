#include "../includes/fractol_bonus.h"

int	scroll_mouse(int scroll, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		scale;

	scale = 0.0;
	if ((scroll == ZOOM_IN) || (scroll == ZOOM_OUT && fractol->zoom <= 3))
	{
		mouse.r = x * fractol->factor.r + fractol->min.r;
		mouse.i = y * fractol->factor.i + fractol->min.i;
		if (scroll == ZOOM_IN)
		{
			scale = 0.8;
			fractol->max_iter += 5;
		}
		else
		{
			scale = 1.25;
			fractol->max_iter -= 5;
		}
		fractol->zoom *= scale;
		reset_scale(mouse, scale, fractol);
		redraw_fractol(fractol);
	}
	return (0);
}

void	reset_scale(t_complex mouse, double scale, t_fractol *fractol)
{
	fractol->min.r = mouse.r + (fractol->min.r - mouse.r) * scale;
	fractol->max.r = mouse.r + (fractol->max.r - mouse.r) * scale;
	fractol->min.i = mouse.i + (fractol->min.i - mouse.i) * scale;
	fractol->max.i = mouse.i + (fractol->max.i - mouse.i) * scale;
}

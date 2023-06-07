#include "../includes/fractol.h"

static double	complex_magnitude(t_complex coord);

int	calculate_mandelbrot(t_fractol *fractol, int x, int y)
{
	t_complex	coord;
	t_complex	coord_pow;
	int			iter_count;

	fractol->c.r = fractol->min.r + x * fractol->factor.r;
	fractol->c.i = fractol->min.i + y * fractol->factor.i;
	iter_count = 0;
	coord.r = 0;
	coord.i = 0;
	coord_pow = coord;
	while (complex_magnitude(coord) <= 4 && iter_count < fractol->max_iter)
	{
		coord.i = 2 * coord.r * coord.i + fractol->c.i;
		coord.r = coord_pow.r - coord_pow.i + fractol->c.r;
		coord_pow.r = coord.r * coord.r;
		coord_pow.i = coord.i * coord.i;
		iter_count++;
	}
	return (iter_count);
}

int	calculate_julia(t_fractol *fractol, int x, int y)
{
	t_complex	coord;
	t_complex	current_coord;
	int			iter_count;

	iter_count = 0;
	coord.r = fractol->min.r + x * fractol->factor.r;
	coord.i = fractol->min.i + y * fractol->factor.i;
	while (complex_magnitude(coord) <= 4 && iter_count < fractol->max_iter)
	{
		current_coord.r = coord.r;
		coord.r = coord.r * coord.r - coord.i * coord.i + fractol->c.r;
		coord.i = 2 * current_coord.r * coord.i + fractol->c.i;
		iter_count++;
	}
	return (iter_count);
}

int	calculate_burning_ship(t_fractol *fractol, int x, int y)
{
	t_complex	coord;
	t_complex	current_coord;
	int			iter_count;

	fractol->c.r = fractol->min.r + x * fractol->factor.r;
	fractol->c.i = fractol->min.i + y * fractol->factor.i;
	coord.r = 0;
	coord.i = 0;
	iter_count = 0;
	while (complex_magnitude(coord) <= 4 && iter_count < fractol->max_iter)
	{
		current_coord.r = coord.r;
		coord.r = coord.r * coord.r - coord.i * coord.i + fractol->c.r;
		if (2 * current_coord.r * coord.i < 0)
		{
			coord.i = 2 * current_coord.r * coord.i * (-1) + fractol->c.i;
		}
		else
		{
			coord.i = 2 * current_coord.r * coord.i + fractol->c.i;
		}
		iter_count++;
	}
	return (iter_count);
}

static double	complex_magnitude(t_complex coord)
{
	return (coord.r * coord.r + coord.i * coord.i);
}

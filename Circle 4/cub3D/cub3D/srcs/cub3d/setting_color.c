#include "cub3d.h"

int	setting_color(char *color_info)
{
	int	r;
	int	g;
	int	b;
	int	value;
	int	color;

	valid_color(color_info);
	value = -1;
	r = setting_rgb(color_info, &value) * 256 * 256;
	g = setting_rgb(color_info, &value) * 256;
	b = setting_rgb(color_info, &value);
	color = r + g + b;
	free(color_info);
	return (color);
}

int	setting_rgb(char *color_info, int *value)
{
	int	rgb;

	rgb = 0;
	while (color_info[++(*value)] && ft_isdigit(color_info[*value]))
	{
		rgb = rgb * 10 + (color_info[*value] - '0');
	}
	if (rgb < 0 || 255 < rgb)
	{
		exit_program("Invalid RGB format.");
	}
	return (rgb);
}

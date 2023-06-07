#include "../includes/fractol.h"

static int		get_integer_length(int integer);
static double	after_dot(const char *s, double lf);

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			index;
	unsigned char	string1;
	unsigned char	string2;

	index = 0;
	while ((str1[index] != '\0' || str2[index] != '\0'))
	{
		string1 = str1[index];
		string2 = str2[index];
		if (string1 != string2)
		{
			return (string1 - string2);
		}
		index ++;
	}
	return (0);
}

double	ft_strtod(const char *s)
{
	int		sign;
	double	lf;

	lf = 0;
	sign = 1;
	while (*s)
	{
		if (*s == '.')
		{
			s++;
			break ;
		}
		if (*s == '-')
			sign = -1;
		else
		{
			lf *= 10;
			lf += *s - '0';
		}
		s++;
	}
	return (lf = sign * after_dot(s, lf));
}

static double	after_dot(const char *s, double lf)
{
	int		tmp;
	int		level;

	level = 0;
	tmp = 0;
	while (*s)
	{
		tmp *= 10;
		tmp += *s - '0';
		level++;
		s++;
	}
	return (lf += (double)tmp * pow(0.1, level));
}

char	*ft_itoa(int integer)
{
	int		front;
	int		back;
	char	*result;

	front = 0;
	back = get_integer_length(integer);
	result = (char *)malloc(back + 1);
	if (result == NULL)
	{
		exit_program(-1);
	}
	if (integer < 0)
	{
		result[front++] = '-';
		integer *= -1;
	}
	result[back--] = '\0';
	while (front <= back)
	{
		result[back--] = integer % 10 + '0';
		integer /= 10;
	}
	return (result);
}

static int	get_integer_length(int integer)
{
	int	length;

	if (integer < 0)
	{
		length = 2;
	}
	else
	{
		length = 1;
	}
	while (integer / 10 != 0)
	{
		length ++;
		integer /= 10;
	}
	return (length);
}

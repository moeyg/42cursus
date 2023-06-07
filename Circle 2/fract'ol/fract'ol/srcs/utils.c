#include "../includes/fractol.h"

static int		get_integer_length(int integer);
static double	process_fractional_part(const char *str, double result);

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

double	ft_strtod(const char *str)
{
	int		sign;
	double	result;

	sign = 1;
	result = 0.0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		result += process_fractional_part(str, 0.0);
	}
	result *= sign;
	return (result);
}

static double	process_fractional_part(const char *str, double result)
{
	int	digit_count;

	digit_count = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		digit_count++;
		str++;
	}
	return (result * pow(0.1, digit_count));
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

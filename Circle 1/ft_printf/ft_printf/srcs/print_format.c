#include "ft_printf.h"

void    print_char(char character, int *count)
{
	write(1, &character, 1);
	*count += 1;
}

void    print_string(char *string, int *count)
{
	unsigned int	index;

	index = 0;
	if (string == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (string[index] != '\0')
	{
		write(1, &string[index], 1);
		index ++;
	}
	*count += index;
}

void    print_int(int integer, int *count)
{
	char	num;

	if (integer == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
        	return ;
	}
	if (integer < 0)
	{
        	write(1, "-", 1);
        	*count += 1;
        	integer = -integer;
	}
	if (integer > 9)
	{
        	print_int(integer / 10, count);
	}
	num = (integer % 10) + '0';
	write(1, &num, 1);
	*count += 1;
}

void    print_unsigned_int(unsigned int integer, int *count)
{
	char	num;

	if (integer / 10 == 0)
    {
		num = integer + '0';
    }
	else
	{
		print_unsigned_int((integer / 10), count);
	}
	num = (integer % 10) + '0';
	write(1, &num, 1);
	*count += 1;
}

void    print_hexadecimal(char specifier, unsigned long hexadecimal, int *count)
{
    char    *base;

    if (specifier == 'x')
    {
        base = BASE_LOWERCASE;
    }
    if (specifier == 'X')
    {
        base = BASE_UPPERCASE;
    }
    if (hexadecimal > 15)
    {
        print_hexadecimal(specifier, hexadecimal / 16, count);
    }
    write(1, &base[hexadecimal % 16], 1);
    *count += 1;
}

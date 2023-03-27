#include "ft_printf.h"

static void	parse_specifier(const char format, va_list *ap, int *count);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			parse_specifier(*format, &ap, &count);
		}
		else
        {
			write(1, format, 1);
			count ++;
        }
		format ++;
	}
	va_end(ap);
	return (count);
}

static void	parse_specifier(const char specifier, va_list *ap, int *count)
{
	if (specifier == 'c')
		print_char(va_arg(*ap, int), count);
	if (specifier == 's')
		print_string(va_arg(*ap, char *), count);
	if (specifier == 'p')
	{
		*count += write(1, "0x", 2);
		print_hexadecimal('x', va_arg(*ap, unsigned long), count);
	}
	if (specifier == 'd' || specifier == 'i')
		print_int(va_arg(*ap, int), count);
	if (specifier == 'u')
		print_unsigned_int(va_arg(*ap, unsigned int), count);
	if (specifier == 'x' || specifier == 'X')
		print_hexadecimal(specifier, va_arg(*ap, unsigned int), count);
	if (specifier == '%')
		*count += write(1, "%", 1);
}
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE_UPPERCASE "0123456789ABCDEF"
# define BASE_LOWERCASE "0123456789abcdef"

# include <unistd.h>
# include <stdarg.h>

int     ft_printf(const char *format, ...);

void    print_char(char character, int *count);
void    print_string(char *string, int *count);
void    print_int(int integer, int *count);
void    print_unsigned_int(unsigned int integer, int *count);
void    print_hexadecimal(char specifier, unsigned long hexadecimal, int *count);

#endif
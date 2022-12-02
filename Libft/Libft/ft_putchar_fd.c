#include "libft.h"

void    ft_putchar_fd(char character, int file_descriptor)
{
    write(file_descriptor, &character, 1);
}
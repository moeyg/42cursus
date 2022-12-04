#include "libft.h"

void    ft_putnbr_fd(int integer, int file_descriptor)
{
    unsigned int    num;

    num = integer;
    if (integer < 0)
    {
        ft_putchar_fd('-', file_descriptor);
        num = -integer;
    }
    if (num >= 10)
        ft_putnbr_fd(num / 10, file_descriptor);
    ft_putchar_fd(num % 10 + '0', file_descriptor);
}
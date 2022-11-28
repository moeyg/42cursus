#include "libft.h"

int ft_toupper(int ascii_num)
{
    if ('a' <= ascii_num && ascii_num <= 'z')
    {
        ascii_num -= 32;
    }
    return (ascii_num);
}
#include "libft.h"

int ft_tolower(int ascii_num)
{
    if ('A' <= ascii_num && ascii_num <= 'Z')
    {
        ascii_num += 32;
    }
    return (ascii_num);
}
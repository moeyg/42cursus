#include "libft.h"

int ft_isprint(int ascii_num)
{
    if (32 <= ascii_num && ascii_num <= 128)
        return (1);
    return (0);
}
#include "libft.h"

int ft_isdigit(int ascii_num)
{
    if ('0' <= ascii_num && ascii_num <= '9')
        return (1);
    return (0);
}
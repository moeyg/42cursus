#include "libft.h"

int ft_isprint(int c)
{
    if (32 <= c && c <= 128)
        return (1);
    return (0);
}
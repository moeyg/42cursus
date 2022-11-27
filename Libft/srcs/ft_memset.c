#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
    size_t  index;

    index = 0;
    while (index < len)
    {
        *((unsigned char *)b + index) = (unsigned char)c;
        index ++;
    }
    return (b);
}
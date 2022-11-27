#include "libft.h"

void *ft_memset(void *pointer, int value, size_t length)
{
    size_t  index;

    index = 0;
    while (index < length)
    {
        *((unsigned char *)pointer + index) = (unsigned char)value;
        index ++;
    }
    return (pointer);
}
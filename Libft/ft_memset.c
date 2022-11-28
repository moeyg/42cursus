#include "libft.h"

void    *ft_memset(void *ptr, int value, size_t length)
{
    size_t          index;
    unsigned char   *pointer;

    index = 0;
    pointer = (unsigned char *)ptr;
    value = (unsigned char)value;
    while (index < length)
    {
        pointer[index] = value;
        index ++;
    }
    return (&pointer[index]);
}
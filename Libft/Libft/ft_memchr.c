#include "libft.h"

void    *ft_memchr(const void *ptr, int value, size_t length)
{
    size_t          index;
    unsigned char   *pointer;

    index = 0;
    pointer = (unsigned char *)ptr;
    value = (unsigned char)value;
    while (index < length)
    {
        if (pointer[index] == value)
            return (&pointer[index]);
        index ++;
    }
    return (0);
}
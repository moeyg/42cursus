#include "libft.h"

void *ft_memmove(void *dest, const void *source, size_t length)
{
    size_t          index;
    unsigned char   *dest_buffer;
    unsigned char   *source_buffer;

    index = 0;
    dest_buffer = (unsigned char *)dest;
    source_buffer = (unsigned char *)source;
    if (dest == source || length == 0)
        return (dest);
    if (dest < source)
    {
        while (index < length)
        {
            *(dest_buffer + index) = *(source_buffer + index);
            index ++;
        }
    }
    else
    {
        while (length != 0)
            *(dest_buffer + length) = *(source_buffer + length);
            length --;
    }
    return (dest);
}
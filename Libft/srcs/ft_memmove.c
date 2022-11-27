#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t length)
{
    unsigned char   *dest_buffer;
    unsigned char   *source_buffer;

    dest_buffer = (unsigned char *)dest;
    source_buffer = (unsigned char *)src;
    if (dest == src || length == 0)
        return (dest);
    if (dest < src)
    {
        while (length != 0)
            *dest_buffer++ = *source_buffer++;
    }
    else
    {
        while (length != 0)
            *(dest_buffer + length) = *(source_buffer + length);
            length --;
    }
    return (dest);
}
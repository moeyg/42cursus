#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t length)
{
    unsigned char   *dest_buffer;
    unsigned char   *src_buffer;

    dest_buffer = (unsigned char *)dest;
    src_buffer = (unsigned char *)src;
    if (dest == src || length == 0)
        return (dest);
    if (dest < src)
    {
        while (length != 0)
            *dest_buffer++ = *src_buffer++;
    }
    else
    {
        while (length != 0)
            *(dest_buffer + length) = *(src_buffer + length);
            length --;
    }
    return (dest);
}
#include <libft.h>

void    *ft_memcpy(void *dest, const void *source, size_t length)
{
    size_t  index;

    index = 0;
    if (length == 0 || dest == source)
        return (dest);
    if (dest == 0 && source == 0)
        return (0);
    while (index < length)
    {
        *((unsigned char *)dest + index) = *((unsigned char *)source + index);
        index ++;
    }
    return (dest);
}
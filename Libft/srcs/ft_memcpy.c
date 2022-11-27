#include <libft.h>

void    *ft_memcpy(void *dest, const void *src, size_t length)
{
    size_t  index;

    index = 0;
    if (length == 0 || dest == src)
        return (dest);
    if (dest == 0 && src == 0)
        return (0);
    while (index < length)
    {
        *((unsigned char *)dest + index) = *((unsigned char *)src + index);
        index ++;
    }
    return (dest);
}
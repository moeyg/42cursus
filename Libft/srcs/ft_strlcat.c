#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
    size_t  index;
    size_t  dest_length;
    size_t  src_length;

    index = 0;
    dest_length = ft_strlen(dest);
    src_length = ft_strlen(src);
    if (dest == '\0' || src == '\0')
        return (0);
    if (dest_length >= dest_size - 1)
        return (dest_length + src_length);
    while (src[index] != '\0'
            && index < dest_size - dest_length - 1)
    {
        dest[dest_length + index] = src[index];
        index ++;
    }
    dest[dest_length + index] = '\0';
    return (dest_length + src_length);
}
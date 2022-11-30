#include "libft.h"

char    *strdup(const char *src)
{
    size_t  index;
    size_t  length;
    char    *dest;

    length = ft_strlen(src);
    if (!(dest = (char *)malloc(sizeof(char) * (length + 1))))
        return (0);
    index = 0;
    while (index < length)
    {
        dest[index] = src[index];
        index ++;
    }
    dest[index] = '\0';
    return (dest);
}
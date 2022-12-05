#include "libft.h"

char    *ft_strdup(const char *src)
{
    size_t  index;
    size_t  length;
    char    *dest;

    length = ft_strlen(src);
    dest = (char *)malloc(sizeof(char) * (length + 1));
    if (!(dest))
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
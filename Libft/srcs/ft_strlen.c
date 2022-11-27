#include "libft.h"

size_t  strlen(const char *s)
{
    size_t  index;

    index = 0;
    while (s[index] != '\0')
        index ++;
    return (index);
}
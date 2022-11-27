#include "libft.h"

size_t  strlen(const char *string)
{
    size_t  index;

    index = 0;
    while (string[index] != '\0')
        index ++;
    return (index);
}
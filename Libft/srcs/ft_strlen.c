// #include "libft.h"
#include <stdio.h>

size_t  ft_strlen(const char *string)
{
    size_t  length;

    length = 0;
    while (string[length] != '\0')
    {
        length ++;
    }
    return (length);
}
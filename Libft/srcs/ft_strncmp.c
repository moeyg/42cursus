#include "libft.h"

int ft_strncmp(const char *str1, const char *str2, size_t length)
{
    while (length > 0 && *str1 != '\0' && *str2 != '\0')
    {
        if (str1 != str2)
            return ((unsigned char *)str1 - (unsigned char *)str2);
        str1 ++;
        str2 ++;
        length --;
    }
    return (0);
}
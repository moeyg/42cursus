#include "libft.h"

int ft_memcmp(const void *str1, const void *str2, size_t length)
{
    size_t          index;
    unsigned char   *string1;
    unsigned char   *string2;
    
    string1 = (unsigned char *)str1;
    string2 = (unsigned char *)str2;
    while (index < length)
    {
        if (string1[index] != string2[index])
            return (string1[index] - string2[index]);
        index ++;
    }
    return (0);
}
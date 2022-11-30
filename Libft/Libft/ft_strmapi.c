#include "libft.h"

char *ft_strmapi(char const *str, char (*foo)(unsigned int, char))
{
    size_t  index;
    size_t  length;
    char    *result;

    if (*str == '\0')
        return (0);
    index = 0;
    length = ft_strlen(str);
    if (!(result = (char *)malloc(length + 1)))
        return (0);
    while (index < length)
    {
        result[index] = foo(index, str[index]);
        index ++;
    }
    result[index] = '\0';
    return (result);
}
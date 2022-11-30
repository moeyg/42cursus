#include "libft.h"

char    *ft_substr(char const *str, unsigned int start, size_t length)
{
    char            *result;
    unsigned int    str_length;

    if (str == 0)
        return (0);
    str_length = ft_strlen(str);
    if (start >= str_length)
        return (ft_strdup(""));
    if (!(result = (char *)malloc(sizeof(char) * (length + 1))))
        return (0);
    ft_memmove(result, str + start, length);
    result[length] = 0;
    return (result);
}
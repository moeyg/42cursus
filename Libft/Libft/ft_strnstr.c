#include "libft.h"

char	*ft_strnstr(const char *str, const char *content, size_t length)
{
    size_t  i;
    size_t  j;

    if (*content == 0)
        return ((char *)str);
    i = 0;
    while (i < length && str[i] != '\0')
    {
        j = 0;
        while (str[i + j] == content[j] && i + j < length)
        {
            if (content[j] == 0)
                return ((char *)&str[i]);
            j ++;
        }
        i ++;
    }
    return (0);
}
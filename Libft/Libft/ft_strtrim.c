#include "libft.h"

char	*ft_strtrim(char const *str, char const *delete)
{
    size_t  start;
    size_t  end;
    char    *result;

    start = 0;
    end = ft_strlen(str) - 1;
    if (str != '\0' && delete != '\0')
    {
        while (str[start] != '\0' && ft_strchr(delete, str[start]))
            start ++;
        while (str[end] != '\0' && ft_strchr(delete, str[end]))
            end --;
        if (!(result = (char *)malloc(end - start + 1)))
            return (0);
        ft_strlcpy(result, &str[start], end - start + 1);
    }
    return (result);
}
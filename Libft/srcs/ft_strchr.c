#include "libft.h"

char	*ft_strchr(const char *str, int ascii_num)
{
    size_t  index;

    index = 0;
    str = (char *)str;
    ascii_num = (char)ascii_num;
    while (str[index] != '\0')
    {
        if (str[index] == ascii_num)
            return (str[index]);
        index ++;
    }
    return (0);
}
#include "libft.h"

char	*ft_strchr(const char *str, int ascii_num)
{
    size_t  index;

    index = 0;
    ascii_num = (char)ascii_num;
    while (str[index] != '\0')
    {
        if (str[index] == ascii_num)
            return ((char *)&str[index]);
        index ++;
    }
    return (0);
}
#include "libft.h"

void    ft_striteri(char *str, void (*foo)(unsigned int, char*))
{
    size_t  index;

    if (*str == '\0')
        return ;
    index = 0;
    while (str[index] != '\0')
    {
        foo(index, &str[index]);
        index ++;
    }
}
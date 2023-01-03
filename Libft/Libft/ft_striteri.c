#include "libft.h"

void    ft_striteri(char *str, void (*func)(unsigned int, char*))
{
    size_t  index;

    if (*str == NULL)
        return ;
    index = 0;
    while (str[index] != '\0')
    {
        func(index, &str[index]);
        index ++;
    }
}
#include "libft.h"

void    ft_putstr_fd(char *str, int file_descriptor)
{
    size_t  index;

    index = 0;
    if (str[index] == '\0')
        return ;
    while (str[index] != '\0')
    {
        write(file_descriptor, str[index], 1);
        index ++;
    }
}

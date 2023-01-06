#include "libft.h"

void    ft_putendl_fd(char *str, int file_descriptor)
{
    if (*str == '\0')
        return ;
    while (*str != '\0')
    {
        write(file_descriptor, str, 1);
        str ++;
    }
    write(file_descriptor, "\n", 1);
}
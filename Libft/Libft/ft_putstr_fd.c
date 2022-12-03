#include "libft.h"

void    ft_putstr_fd(char *str, int file_descriptor)
{
    write(file_descriptor, str, ft_strlen(str));
}
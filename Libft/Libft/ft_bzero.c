#include "libft.h"

void    ft_bzero(void *str, size_t size)
{
    ft_memset(str, 0, size);
}
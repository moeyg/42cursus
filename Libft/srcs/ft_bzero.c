#include "libft.h"

void    ft_bzero(void *string, size_t size)
{
    ft_memset(string, 0, size);
}
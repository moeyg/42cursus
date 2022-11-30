#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void    *result;

    if (!(result = malloc(size * count)))
        return (0);
    ft_bzero(result, size * count);
    return (result);
}
#include "libft.h"

int	ft_isascii(int ascii_num)
{
    if (0 <= ascii_num && ascii_num <= 127)
        return (1);
    return (0);
}
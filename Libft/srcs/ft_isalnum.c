#include "libft.h"

int ft_isalnum(int ascii_num)
{
    if (ft_isalpha(ascii_num) || ft_isdigit(ascii_num))
        return (1);
    return (0);
}
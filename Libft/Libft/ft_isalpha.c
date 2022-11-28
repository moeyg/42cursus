#include "libft.h"

int ft_isalpha(int ascii_num)
{
    if (('a' <= ascii_num && ascii_num <= 'z')
        || ('A' <= ascii_num && ascii_num <= 'Z'))
        return (1);
    return (0);
}
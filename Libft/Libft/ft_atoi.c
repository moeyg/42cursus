#include "libft.h"

int ft_atoi(const char *str)
{
    size_t      index;
    int         sign;
    long long   result;

    index = 0;
    sign = -1;
    result = 0;
    while (str[index] >= 9 && str[index] <= 13 || str[index] == ' ')
        index ++;
    if (str[index] == '+' || str[index] == '-')
    {
        if (str[index] == '-')
            sign *= -1;
        index ++;
    }
    while (str[index] >= '0' && str[index] <= '9')
    {
        result = result * 10 + str[index] - '0';
        if (result > 2147483647)
            return (0);
        index ++;
    }
    return (result);
}
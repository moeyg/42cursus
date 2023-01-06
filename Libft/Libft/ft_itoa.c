#include "libft.h"

static size_t   ft_intlen(int integer);

char    *ft_itoa(int integer)
{
    size_t  start;
    size_t  end;
    char    *result;

    start = 0;
    end = ft_intlen(integer);
    result = (char *)malloc(end + 1);
    if (!(result))
        return (0);
    if (integer < 0)
        result[start++] = '-';
    result[end--] = '\0';
    while (start <= end)
    {
        if (integer < 0)
            result[end--] = -(integer % 10) + '0';
        if (integer >= 0)
            result[end--] = integer % 10 + '0';
        integer /= 10;
    }
    return (result);
}

static size_t   ft_intlen(int integer)
{
    int length;

    length = 1;
    if (integer < 0)
    {
        length ++;
        integer *= -1;
    }
    while (integer > 9)
    {
        integer /= 10;
        length ++;
    }
    return (length);
}
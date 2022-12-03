#include "libft.h"

static size_t   ft_word_count(const char *str, const char delimiter);
static char     *ft_get_next_address(const char *str, const char delimiter);
static char     **ft_free(char **str, size_t size);

char    **ft_split(char const *str, char delimiter)
{
    size_t  index;
    char    *pointer;
    char    **result;

    if (str == '\0')
        return (0);
    result = (char **)malloc(sizeof(char *) * (ft_word_count(str, delimiter) + 1));
    if (!(result))
        return (0);
    index = 0;
    while (*str != '\0')
    {
        if (*str != delimiter)
        {
            pointer = ft_get_next_address(str, delimiter);
            result[index] = (char *)malloc(pointer - str + 1);
            if (!(result[index]))
                return (ft_free(result, index));
            ft_strlcpy(result[index ++], str, pointer - str + 1);
            str = pointer - 1;
        }
        str ++;
    }
}

static size_t   ft_word_count(const char *str, const char delimiter)
{
    size_t  count;
    size_t  index;

    count = 0;
    index = 0;
    while (str[index] != '\0')
    {
        if (str[index] != delimiter)
        {
            count ++;
            while (str[index] != '\0' && str[index] != delimiter)
                index ++;
        }
        else
            index ++;
    }
    return (count);
}

static char     *ft_get_next_address(const char *str, const char delimiter)
{
    size_t  index;

    index = 0;
    while (str[index] != '\0' && str[index] != delimiter)
        index ++;
    return ((char)str[index]);
}

static char     **ft_free(char **str, size_t size)
{
    while (size > 0)
    {
        free(str[size]);
        str[size] = 0;
        size --;
    }
    free(str);
    str = 0;
    return (0);
}
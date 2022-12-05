#include "libft.h"

static size_t   ft_word_count(const char *str, const char delimiter);
static char     *ft_str_duplicate(const char *str, const char delimiter);
static char     **ft_free(char **str);

char    **ft_split(char const *str, char delimiter)
{
    size_t  index;
    size_t  count;
    char    **result;

    if (str == '\0')
        return (0);
    count = ft_word_count(str, delimiter);
    result = (char **)ft_calloc(count + 1, sizeof(char *));
    if (!(result))
        return (0);
    index = 0;
    while (*str != '\0' && index < count)
    {
        if (*str != delimiter)
        {
            result[index++] = ft_str_duplicate(&*str, delimiter);
            if (!(result))
                return (ft_free(result));
            while (*str != '\0' && *str != delimiter)
                str ++;
        }
        else
            str ++;
    }
    return (result);
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

static char     *ft_str_duplicate(const char *src, const char delimiter)
{
    size_t  length;
    char    *dest;

    length = 0;
    while (src[length] != '\0' && src[length] != delimiter)
        length ++;
    dest = (char *)ft_calloc(length + 1, sizeof(char));
    if (!(dest))
        return (0);
    ft_strlcpy(dest, src, length + 1);
    return (dest);
}

static char     **ft_free(char **str)
{
    size_t  index;

    index = 0;
    while (str[index] != '\0')
    {
        free(str[index]);
        index ++;
    }
    free(str);
    return (0);
}
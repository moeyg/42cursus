#include "libft.h"

char    *ft_strjoin(char const *prefix, char const *suffix)
{
    size_t  prefix_length;
    size_t  suffix_length;
    char    *result;

    if (prefix == 0 || suffix == 0)
        return (0);
    prefix_length = ft_strlen(prefix);
    suffix_length = ft_strlen(suffix);
    if (!(result = (char *)malloc(prefix_length + suffix_length + 1)))
        return (0);
    ft_strlcpy(result, prefix, prefix_length);
    ft_strlcat(result + prefix_length, suffix, suffix_length);
    result[prefix_length + suffix_length] = '\0';
    return (result);
}

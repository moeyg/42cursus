#include "libft.h"

char	*ft_strnstr(const char *str, const char *content, size_t length)
{
    size_t  index_str;
    size_t  index_content;

    if (*content == 0)
        return ((char *)str);
    index_str = 0;
    while (index_str < length && str[index_str] != '\0')
    {
        index_content = 0;
        while (str[index_str + index_content] == content[index_content] 
                && index_str + index_content < length)
        {
            if (content[index_content] == '\0')
                return ((char *)&str[index_str]);
            index_content ++;
        }
        index_str ++;
    }
    return (0);
}
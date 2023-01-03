#include "libft.h"

int ft_lstsize(t_list *list)
{
    int  size;

    size = 0;
    while (list != NULL)
    {
        size ++;
        list = list->next;
    }
    return (size);
}
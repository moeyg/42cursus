#include "libft.h"

void    ft_lstiter(t_list *list, void (*func)(void *))
{
    if (list == NULL || func == NULL)
        return ;
    while (list != NULL)
    {
        func(list->content);
        list = list->next;
    }
}
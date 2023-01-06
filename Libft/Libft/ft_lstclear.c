#include "libft.h"

void    ft_lstclear(t_list **list, void (*del)(void *))
{
    t_list  *current;

    if (list == NULL || del == NULL)
        return ;
    while (*list != NULL)
    {
        current = (*list)->next;
        ft_lstdelone(*list, del);
        *list = current;
    }
    *list = 0;
}
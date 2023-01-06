#include "libft.h"

void    ft_lstadd_front(t_list **list, t_list *new)
{
    if (list == NULL || new == NULL)
        return ;
    new->next = *list;
    *list = new;
}
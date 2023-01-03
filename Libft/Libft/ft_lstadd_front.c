#include "libft.h"

void    ft_lstadd_front(t_list **list, t_list *new)
{
    if (new == NULL)
        return ;
    new->next = *list;
    *list = new;
}
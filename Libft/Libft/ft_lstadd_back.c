#include "libft.h"

void    ft_lstadd_back(t_list **list, t_list *new)
{
    t_list *node;

    if (list == NULL || new == NULL)
        return ;
    node = ft_lstlast(*list);
    if (node == NULL)
        *list = new;
    else
        node->next = new;
}

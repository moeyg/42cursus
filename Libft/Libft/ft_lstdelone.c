#include "libft.h"

void    ft_lstdelone(t_list *list, void (*del)(void *))
{
    if (list == NULL || del == NULL)
        return ;
    del(list->content);
    free(list);
}
#include "libft.h"

t_list  *ft_lstmap(t_list *list, void *(*func)(void *),
void (*del)(void *))
{
    t_list  *new_list;
    t_list  *head;

    if (list == NULL || func == NULL || del == NULL)
        return (NULL);
    head = NULL;
    while (list != NULL)
    {
        new_list = ft_lstnew(func(list->content));
        if (new_list == NULL)
        {
            ft_lstclear(&head, del);
            return (NULL);
        }
        ft_lstadd_back(&head, new_list);
        list = list->next;
    }
    return (head);
}
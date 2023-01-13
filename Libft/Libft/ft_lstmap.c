/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:45:28 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 16:45:29 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *list, void *(*func)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*head;
	void	*data;

	if (list == NULL || func == NULL || del == NULL)
		return (NULL);
	head = NULL;
	while (list != NULL)
	{
		data = func(list->content);
		new_list = ft_lstnew(data);
		if (new_list == NULL)
		{
			del(data);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_list);
		list = list->next;
	}
	return (head);
}

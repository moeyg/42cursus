/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:31 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 16:32:03 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*current;

	if (list == NULL || del == NULL)
	{
		return ;
	}
	while (*list != NULL)
	{
		current = (*list)->next;
		ft_lstdelone(*list, del);
		*list = current;
	}
	*list = 0;
}

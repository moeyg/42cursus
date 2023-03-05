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

void	ft_lstclear(t_list **head_node, void (*del)(void *))
{
	t_list	*current_node;

	if (head_node == NULL || del == NULL)
	{
		return ;
	}
	while (*head_node != NULL)
	{
		current_node = (*head_node)->next;
		ft_lstdelone(*head_node, del);
		*head_node = current_node;
	}
	*head_node = 0;
}

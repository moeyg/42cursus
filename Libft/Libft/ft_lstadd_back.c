/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:16 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/16 16:33:46 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **head_node, t_list *new_node)
{
	t_list	*tail_node;

	if (lhead_node == NULL || new_node == NULL)
	{
		return ;
	}
	tail_node = ft_lstlast(*head_node);
	if (tail_node == NULL)
	{
		*head_node = new_node;
	}
	else
	{
		tail_node->next = new_node;
	}
}

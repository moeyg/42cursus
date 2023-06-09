/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:16 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **head_node, t_list *new_node)
{
	t_list	*tail_node;

	if (*head_node == NULL || new_node == NULL)
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

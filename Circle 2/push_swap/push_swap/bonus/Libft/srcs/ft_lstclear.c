/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:31 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **head_node, void (*del)(void *))
{
	t_list	*next_node;

	if (head_node == NULL || del == NULL)
	{
		return ;
	}
	while (*head_node != NULL)
	{
		next_node = (*head_node)->next;
		ft_lstdelone(*head_node, del);
		*head_node = next_node;
	}
	*head_node = 0;
}

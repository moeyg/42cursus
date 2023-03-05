/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:26 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/16 16:32:02 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **head_node, t_list *new_node)
{
	if (head_node == NULL || new_node == NULL)
	{
		return ;
	}
	new_node->next = *head_node;
	*head_node = new_node;
}

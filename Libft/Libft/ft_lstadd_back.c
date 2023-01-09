/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:16 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 16:31:59 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*node;

	if (list == NULL || new == NULL)
		return ;
	node = ft_lstlast(*list);
	if (node == NULL)
		*list = new;
	else
		node->next = new;
}

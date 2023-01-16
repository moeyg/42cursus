/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:16 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/16 16:33:46 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *data)
{
	t_list	*node;

	if (list == NULL || data == NULL)
		return ;
	node = ft_lstlast(*list);
	if (node == NULL)
		*list = data;
	else
		node->next = data;
}

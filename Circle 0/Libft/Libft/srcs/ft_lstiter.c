/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:41 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 16:32:08 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *node, void (*func)(void *))
{
	if (node == NULL || func == NULL)
	{
		return ;
	}
	while (node != NULL)
	{
		func(node->content);
		node = node->next;
	}
}

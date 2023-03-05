/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:47 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 16:32:10 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *node)
{	
	if (node == NULL)
	{
		return (NULL);
	}
	while (node->next != NULL)
	{
		node = node->next;
	}
	return (node);
}

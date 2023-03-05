/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:50:36 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 16:32:05 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *delete_node, void (*del)(void *))
{
	if (delete_node == NULL || del == NULL)
	{
		return ;
	}
	del(delete_node->content);
	free(delete_node);
}

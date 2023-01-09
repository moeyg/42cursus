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

void	ft_lstiter(t_list *list, void (*func)(void *))
{
	if (list == NULL || func == NULL)
		return ;
	while (list != NULL)
	{
		func(list->content);
		list = list->next;
	}
}

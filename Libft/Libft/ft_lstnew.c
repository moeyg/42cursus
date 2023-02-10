/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:45:42 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 16:45:44 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*data;

	data = (t_list *)malloc(sizeof(t_list));
	if (data == NULL)
	{
		return (0);
	}
	data->content = content;
	data->next = NULL;
	return (data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:49:29 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 13:37:50 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*result;
	unsigned long long	memory_size;

	memory_size = count * size;
	if (memory_size > 4294967295)
	{
		return (0);
	}
	result = malloc(memory_size);
	if (result == NULL)
	{
		return (0);
	}
	ft_bzero(result, memory_size);
	return (result);
}

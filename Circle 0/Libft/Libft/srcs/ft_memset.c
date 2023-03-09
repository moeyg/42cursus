/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:53:25 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 14:09:09 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t length)
{
	size_t			index;
	unsigned char	*pointer;

	index = 0;
	pointer = (unsigned char *)ptr;
	while (index < length)
	{
		pointer[index] = (unsigned char)value;
		index ++;
	}
	return (pointer);
}

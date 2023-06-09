/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:53:07 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t length)
{
	size_t			index;
	unsigned char	*destination;
	unsigned char	*source;

	index = 0;
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (length == 0 || dest == src)
	{
		return (dest);
	}
	if (dest == 0 && src == 0)
	{
		return (0);
	}
	while (index < length)
	{
		destination[index] = source[index];
		index ++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:46:10 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 16:46:11 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (dest == src || length == 0)
	{
		return (dest);
	}
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (dest < src)
	{
		while (length-- > 0)
		{
			*destination++ = *source++;
		}
	}
	if (dest >= src)
	{
		while (length-- > 0)
		{
			*(destination + length) = *(source + length);
		}
	}
	return (dest);
}

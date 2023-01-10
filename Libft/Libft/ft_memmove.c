/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:23:14 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/10 21:16:46 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (dest == src || length == 0)
		return (dest);
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (dest < src)
	{
		while (length-- > 0)
			*destination++ = *source++;
	}
	if (dest >= src)
	{
		while (length-- > 0)
			*(destination + length) = *(source + length);
	}
	return (dest);
}

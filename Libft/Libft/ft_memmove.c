/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:23:14 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 15:23:16 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t length)
{
	unsigned char	*dest_buffer;
	unsigned char	*src_buffer;

	if (dest == src || length == 0)
		return (dest);
	dest_buffer = (unsigned char *)dest;
	src_buffer = (unsigned char *)src;
	if (dest < src)
		while (length--)
			*dest_buffer++ = *src_buffer++;
	else
		while (length--)
			*(dest_buffer + length) = *(src_buffer + length);
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:24:12 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 20:37:01 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	index;
	size_t	dest_length;
	size_t	src_length;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	index = 0;
	if (size <= dest_length)
		return (src_length + size);
	while (index < size - dest_length - 1 && src[index])
	{
		dest[dest_length + index] = src[index];
		index++;
	}
	dest[dest_length + index] = '\0';
	return (dest_length + src_length);
}

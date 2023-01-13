/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:28 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 16:47:30 by dogpark          ###   ########.fr       */
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
	while (index < size - dest_length - 1 && src[index] != '\0')
	{
		dest[dest_length + index] = src[index];
		index++;
	}
	dest[dest_length + index] = '\0';
	return (dest_length + src_length);
}

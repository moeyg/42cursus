/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:55:43 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 13:31:48 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	index;
	size_t	src_length;

	index = 0;
	src_length = ft_strlen(src);
	if (dest_size != 0)
	{
		while (src[index] != '\0' && index < dest_size - 1)
		{
			dest[index] = src[index];
			index ++;
		}
		dest[index] = '\0';
	}
	return (src_length);
}

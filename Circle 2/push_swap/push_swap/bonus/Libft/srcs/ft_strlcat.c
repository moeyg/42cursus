/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:28 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 06:01:06 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	index;
	size_t	dest_length;
	size_t	src_length;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	index = 0;
	if (dest == NULL || src == NULL)
		return (0);
	if (dest_size < dest_length + 1)
	{
		return (src_length + dest_size);
	}
	while (src[index] != '\0' && dest_length + index < dest_size - 1)
	{
		dest[dest_length + index] = src[index];
		index ++;
	}
	dest[dest_length + index] = '\0';
	return (src_length + dest_length);
}

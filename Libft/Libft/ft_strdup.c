/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:02 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 16:47:03 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	index;
	size_t	length;
	char	*dest;

	length = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (0);
	index = 0;
	while (index < length)
	{
		dest[index] = src[index];
		index ++;
	}
	dest[index] = '\0';
	return (dest);
}

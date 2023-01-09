/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:55:07 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/09 19:00:43 by moeyg            ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:02 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 06:00:35 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *src)
{
	size_t	index;
	size_t	src_lengthgth;
	char	*dest;

	src_lengthgth = ft_strlen(src);
	dest = (char *)malloc(src_lengthgth + 1);
	if (dest == NULL)
		return (0);
	index = 0;
	while (index < src_lengthgth)
	{
		dest[index] = src[index];
		index ++;
	}
	dest[index] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:32:58 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/10 02:50:36 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*save;
	char		cache;
	size_t		index;

	save = (char *)s;
	cache = (unsigned char)c;
	index = ft_strlen(s);
	while (index > 0)
	{
		if (save[index] == cache)
			return ((char *)save + index);
		index--;
	}
	if (save[index] == cache)
		return ((char *)save);
	return ((char *)0);
}

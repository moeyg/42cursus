/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 22:03:54 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/10 02:50:36 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cache1;
	unsigned char	*cache2;
	size_t			index;

	cache1 = (unsigned char *)s1;
	cache2 = (unsigned char *)s2;
	index = 0;
	while ((index < n) && (cache1[index] || cache2[index]))
	{
		if (cache1[index] != cache2[index])
			return (cache1[index] - cache2[index]);
		index++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:54:44 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/10 02:50:36 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cache_dst;
	unsigned char	*cache_src;

	if ((dst == src) || (!len))
		return (dst);
	if (dst < src)
	{
		cache_dst = (unsigned char *)dst;
		cache_src = (unsigned char *)src;
		while (len--)
			*cache_dst++ = *cache_src++;
	}
	else
	{
		cache_dst = (unsigned char *)dst + (len - 1);
		cache_src = (unsigned char *)src + (len - 1);
		while (len--)
			*cache_dst-- = *cache_src--;
	}
	return (dst);
}

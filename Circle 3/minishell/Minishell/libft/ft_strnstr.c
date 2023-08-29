/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:00:00 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/10 02:50:36 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	h_len;
	size_t	n_len;

	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	index = 0;
	if (n_len == 0)
		return ((char *)haystack);
	if ((n_len > h_len) || (n_len > len))
		return (0);
	if (h_len > len)
		index = len;
	else
		index = h_len;
	while (index >= n_len)
	{
		if (ft_memcmp(haystack, needle, n_len) == 0)
			return ((char *)haystack);
		index--;
		haystack++;
	}
	return (0);
}

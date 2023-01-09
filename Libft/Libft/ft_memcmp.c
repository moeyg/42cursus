/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:52:50 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 15:39:09 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t length)
{
	size_t			index;
	unsigned char	*string1;
	unsigned char	*string2;

	index = 0;
	string1 = (unsigned char *)str1;
	string2 = (unsigned char *)str2;
	while (index < length)
	{
		if (string1[index] != string2[index])
			return (string1[index] - string2[index]);
		index ++;
	}
	return (0);
}

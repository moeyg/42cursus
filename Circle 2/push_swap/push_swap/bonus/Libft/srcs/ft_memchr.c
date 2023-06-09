/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:52:42 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *ptr, int value, size_t length)
{
	size_t			index;
	unsigned char	*pointer;

	index = 0;
	pointer = (unsigned char *)ptr;
	value = (unsigned char)value;
	while (index < length)
	{
		if (pointer[index] == value)
		{
			return (&pointer[index]);
		}
		index ++;
	}
	return (0);
}

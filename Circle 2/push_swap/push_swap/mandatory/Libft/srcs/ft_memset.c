/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:53:25 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *ptr, int value, size_t length)
{
	size_t			index;
	unsigned char	*pointer;

	index = 0;
	pointer = (unsigned char *)ptr;
	while (index < length)
	{
		pointer[index] = (unsigned char)value;
		index ++;
	}
	return (pointer);
}

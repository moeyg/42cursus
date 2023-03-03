/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:54 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 16:47:55 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	size_t	index;
	size_t	length;
	char	*result;

	if (str == NULL)
	{
		return (0);
	}
	index = 0;
	length = ft_strlen(str);
	result = (char *)malloc(length + 1);
	if (result == NULL)
	{
		return (0);
	}
	while (index < length)
	{
		result[index] = func(index, str[index]);
		index ++;
	}
	result[index] = '\0';
	return (result);
}

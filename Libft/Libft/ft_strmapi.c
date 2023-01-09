/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:55:52 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/09 19:02:11 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	size_t	index;
	size_t	length;
	char	*result;

	if (str == NULL)
		return (0);
	index = 0;
	length = ft_strlen(str);
	result = (char *)malloc(length + 1);
	if (result == NULL)
		return (0);
	while (index < length)
	{
		result[index] = func(index, str[index]);
		index++;
	}
	result[index] = 0;
	return (result);
}

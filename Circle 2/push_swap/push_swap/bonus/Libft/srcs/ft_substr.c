/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:56:12 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t length)
{
	char	*result;
	size_t	str_length;

	if (str == NULL)
	{
		return (0);
	}
	str_length = ft_strlen(str);
	if (str_length <= start)
	{
		return (ft_strdup(""));
	}
	if (str_length < length)
	{
		length = str_length;
	}
	result = (char *)malloc(length + 1);
	if (result == NULL)
	{
		return (0);
	}
	ft_memcpy(result, str + start, length);
	result[length] = '\0';
	return (result);
}

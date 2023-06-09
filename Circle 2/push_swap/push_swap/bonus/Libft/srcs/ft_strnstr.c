/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:24:31 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *content, size_t length)
{
	size_t	str_index;
	size_t	content_index;

	if (*content == '\0')
	{
		return ((char *)str);
	}
	str_index = 0;
	while (str_index < length && str[str_index] != '\0')
	{
		content_index = 0;
		while ((str[str_index + content_index] == content[content_index])
			&& (str_index + content_index < length))
		{
			content_index ++;
			if (content[content_index] == '\0')
			{
				return ((char *)&str[str_index]);
			}
		}
		str_index ++;
	}
	return (0);
}

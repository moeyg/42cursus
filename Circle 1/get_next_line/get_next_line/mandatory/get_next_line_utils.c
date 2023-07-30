/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:58:49 by dogpark           #+#    #+#             */
/*   Updated: 2023/03/16 14:58:51 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
	{
		length ++;
	}
	return (length);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	index;
	size_t	dest_length;
	size_t	src_length;

	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	index = 0;
	if (dest == NULL || src == NULL)
		return (0);
	if (dest_size < dest_length + 1)
	{
		return (src_length + dest_size);
	}
	while (src[index] != '\0' && dest_length + index < dest_size - 1)
	{
		dest[dest_length + index] = src[index];
		index ++;
	}
	dest[dest_length + index] = '\0';
	return (src_length + dest_length);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	index;
	size_t	src_length;

	index = 0;
	src_length = ft_strlen(src);
	if (dest_size != 0)
	{
		while (src[index] != '\0' && index < dest_size - 1)
		{
			dest[index] = src[index];
			index ++;
		}
		dest[index] = '\0';
	}
	return (src_length);
}

char	*ft_strdup(const char *src)
{
	size_t	index;
	size_t	src_lengthgth;
	char	*dest;

	src_lengthgth = ft_strlen(src);
	dest = (char *)malloc(src_lengthgth + 1);
	if (dest == NULL)
		return (0);
	index = 0;
	while (index < src_lengthgth)
	{
		dest[index] = src[index];
		index ++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strjoin(char *prefix, char *suffix)
{
	size_t	prefix_length;
	size_t	suffix_length;
	char	*result;

	if (suffix == NULL)
		return (0);
	else if (prefix == NULL && suffix != NULL)
	{
		return (ft_strdup(suffix));
	}
	prefix_length = ft_strlen(prefix);
	suffix_length = ft_strlen(suffix);
	result = (char *)malloc(prefix_length + suffix_length + 1);
	if (result == NULL)
		return (0);
	ft_strlcpy(result, prefix, prefix_length + 1);
	ft_strlcat(result, suffix, prefix_length + suffix_length + 1);
	free(prefix);
	return (result);
}


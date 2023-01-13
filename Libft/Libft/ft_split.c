/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:46:39 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 21:07:39 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, const char c);
static char		*get_next_address(const char *s, const char c);
static char		**free_memory(char **str, size_t size);

char	**ft_split(char const *str, char delimiter)
{
	size_t	index;
	char	**result;
	char	*pointer;

	if (str == NULL)
		return (0);
	result = (char **)malloc(sizeof(char *) * (word_count(str, delimiter) + 1));
	if (result == NULL)
		return (0);
	index = 0;
	while (*str != '\0')
	{
		if (*str != delimiter)
		{
			pointer = get_next_address(str, delimiter);
			result[index] = (char *)malloc(pointer - str + 1);
			if (result[index] == NULL)
				return (free_memory(result, index));
			ft_strlcpy(result[index++], str, pointer - str + 1);
			str = pointer - 1;
		}
		str ++;
	}
	result[index] = 0;
	return (result);
}

static size_t	word_count(const char *str, const char delimiter)
{
	size_t	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str != delimiter)
		{
			count++;
			while (*str != '\0' && *str != delimiter)
				str ++;
		}
		else
			str ++;
	}
	return (count);
}

static char	*get_next_address(const char *str, const char delimiter)
{
	while (*str != '\0' && *str != delimiter)
		str ++;
	return ((char *)str);
}

static char	**free_memory(char **str, size_t size)
{
	while (size > 0)
	{
		free(str[size]);
		str[size] = 0;
		size --;
	}
	free(str);
	str = 0;
	return (0);
}

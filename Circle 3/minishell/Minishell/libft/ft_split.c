/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:44:24 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/10 02:50:36 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	flag;
	size_t	result;

	flag = 0;
	result = 0;
	while (*s)
	{
		if (flag == 0 && *s != c)
		{
			flag = 1;
			result++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (result);
}

static char	*ft_get_word(char const *str, int len)
{
	char	*word;
	int		index;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!(word))
		return ((char *) NULL);
	index = 0;
	while (index < len)
	{
		word[index] = str[index];
		index++;
	}
	word[index] = '\0';
	return (word);
}

static void	ft_free(char **result, int index)
{
	while (index--)
		free(result[index]);
	free(result);
	return ;
}

static int	ft_do_split(char const *s, char c, char **result)
{
	int		index;
	int		cache;
	int		word_count;

	index = 0;
	word_count = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (!(s[index]))
			break ;
		cache = index;
		while (s[index] != c && s[index])
			index++;
		result[word_count] = ft_get_word(s + cache, index - cache);
		if (!(result[word_count]))
		{
			ft_free(result, word_count);
			return (1);
		}
		word_count++;
	}
	result[word_count] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!(s))
		return ((char **) NULL);
	result = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!(result))
		return ((char **) NULL);
	if (ft_do_split(s, c, result))
		return ((char **) NULL);
	return (result);
}

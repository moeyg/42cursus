/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:48:21 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/10 02:50:36 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_start_end(char const *s1, char const *set, int flag)
{
	size_t	len;
	size_t	index;

	len = ft_strlen(s1);
	index = 0;
	if (flag)
	{
		while (index < len)
		{
			if (ft_strchr(set, s1[index]) == 0)
				break ;
			index++;
		}
		return (index);
	}
	else
	{
		while (index < len)
		{
			if (ft_strchr(set, s1[len - index - 1]) == 0)
				break ;
			index++;
		}
		return (len - index);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{	
	char	*result;
	size_t	start;
	size_t	end;

	if (!(s1))
		return (NULL);
	if (!(set))
		return (ft_strdup(s1));
	start = ft_get_start_end(s1, set, 1);
	end = ft_get_start_end(s1, set, 0);
	if (start >= end)
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!(result))
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}

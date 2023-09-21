/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:41:16 by wyoon             #+#    #+#             */
/*   Updated: 2023/09/19 20:46:19 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	index;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	index = ft_strlen(s + start);
	if (index >= len)
		index = len;
	result = malloc(sizeof(char) * (index + 1));
	if (!(result))
		return (NULL);
	ft_strlcpy(result, s + start, index + 1);
	return (result);
}

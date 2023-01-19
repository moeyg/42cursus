/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:22:20 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/09 19:05:39 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *delete)
{
	char	*result;
	size_t	front;
	size_t	back;

	if (str == NULL || delete == NULL)
		return (0);
	front = 0;
	back = ft_strlen(str);
	while (str[front] && ft_strchr(delete, str[front]))
		front ++;
	while (str[back - 1] && ft_strchr(delete, str[back - 1]) && back > front)
		back --;
	result = (char *)malloc(sizeof(char) * (back - front + 1));
	if (result == NULL)
		return (0);
	else
		ft_strlcpy(result, &str[front], back - front + 1);
	return (result);
}

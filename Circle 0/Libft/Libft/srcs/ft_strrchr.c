/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:24:49 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/15 21:01:48 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int code_point)
{
	size_t	index;

	index = ft_strlen(str);
	while (index > 0 && str[index] != (char)code_point)
	{
		index --;
	}
	if (str[index] == (char)code_point)
	{
		return ((char *)(str + index));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:46:50 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/15 21:01:48 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int code_point)
{
	while (*str != '\0')
	{
		if (*str == (char)code_point)
		{
			return ((char *)str);
		}
		str ++;
	}
	if (*str == (char)code_point)
	{
		return ((char *)str);
	}
	return (0);
}

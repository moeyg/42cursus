/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:46:50 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/17 13:52:39 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ascii_num)
{
	while (*str != '\0')
	{
		if (*str == (char)ascii_num)
		{
			return ((char *)str);
		}
		str ++;
	}
	if (*str == (char)ascii_num)
	{
		return ((char *)str);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:23:50 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/09 19:08:21 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ascii_num)
{
	while (*str != '\0') 
	{
		if (*str == (char)ascii_num)
			return ((char *)str);
		str ++;
	}
	if (*str == (char)ascii_num)
		return ((char *)str);
	return (0);
}

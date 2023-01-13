/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:24:49 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/09 20:01:53 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ascii_num)
{
	char	*result;

	result = 0;
	while (*str != '\0')
	{
		if (*str == (char)ascii_num)
			result = (char *)str;
		str ++;
	}
	if ((char)ascii_num == 0)
		return ((char *)str);
	return (result);
}

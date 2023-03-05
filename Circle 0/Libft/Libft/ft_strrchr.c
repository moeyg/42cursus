/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:24:49 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/09 20:01:53 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ascii_num)
{
	size_t	index;

	index = ft_strlen(str);
	while (index > 0 && str[index] != (char)ascii_num)
	{
		index --;
	}
	if (str[index] == (char)ascii_num)
	{
		return ((char *)(str + index));
	}
	return (0);
}

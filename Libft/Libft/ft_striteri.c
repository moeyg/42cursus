/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:55:12 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 13:28:41 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*func)(unsigned int, char*))
{
	size_t	index;

	if (*str == '\0')
		return ;
	index = 0;
	while (str[index] != '\0')
	{
		func(index, &str[index]);
		index ++;
	}
}

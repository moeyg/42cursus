/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:55:12 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

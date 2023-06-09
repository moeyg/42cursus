/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:55:56 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:20:41 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t			index;
	unsigned char	string1;
	unsigned char	string2;

	index = 0;
	while (str1[index] != '\0' || str2[index] != '\0')
	{
		string1 = str1[index];
		string2 = str2[index];
		if (string1 != string2)
		{
			return (string1 - string2);
		}
		index ++;
	}
	return (0);
}

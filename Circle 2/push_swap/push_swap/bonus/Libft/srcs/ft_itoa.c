/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:45:09 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_integer_length(int integer);

char	*ft_itoa(int integer)
{
	int		front;
	int		back;
	char	*result;

	front = 0;
	back = get_integer_length(integer);
	result = (char *)malloc(back + 1);
	if (result == NULL)
	{
		return (0);
	}
	if (integer < 0)
	{
		result[front++] = '-';
		integer *= -1;
	}
	result[back--] = '\0';
	while (front <= back)
	{
		result[back--] = integer % 10 + '0';
		integer /= 10;
	}
	return (result);
}

static int	get_integer_length(int integer)
{
	int	length;

	if (integer < 0)
	{
		length = 2;
	}
	else
	{
		length = 1;
	}
	while (integer / 10 != 0)
	{
		length ++;
		integer /= 10;
	}
	return (length);
}

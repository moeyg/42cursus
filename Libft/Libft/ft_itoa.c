/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:45:09 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 16:45:11 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	}
	result[back--] = 0;
	while (front <= back)
	{
		if (integer < 0)
		{
			result[back--] = -(integer % 10) + '0';
		}
		else
		{
			result[back--] = integer % 10 + '0';
		}
		integer /= 10;
	}
	return (result);
}

static int	get_integer_length(int integer)
{
	int	count;

	if (integer < 0)
	{
		count = 2;
	}
	else
	{
		count = 1;
	}
	while (integer / 10 != 0)
	{
		count ++;
		integer /= 10;
	}
	return (count);
}

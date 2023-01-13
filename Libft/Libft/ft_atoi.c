/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:44:50 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 16:44:52 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				index;
	int					sign;
	unsigned long long	result;

	index = 0;
	sign = 1;
	result = 0;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index ++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index ++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		index ++;
	}
	if (sign < 0 && result > 9223372036854775808ULL)
		return (0);
	if (sign > 0 && result > 9223372036854775807ULL)
		return (-1);
	return (sign * result);
}

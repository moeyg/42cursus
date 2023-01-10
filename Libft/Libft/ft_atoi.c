/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:49:18 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/10 21:15:11 by moeyg            ###   ########.fr       */
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

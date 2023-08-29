/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:32:56 by wyoon             #+#    #+#             */
/*   Updated: 2023/08/10 03:11:58 by wyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	long	sign;
	size_t	index;

	result = 0;
	sign = 1;
	index = 0;
	while (str[index] != '\0' && ft_isspace(str[index]))
		index++;
	if (str[index] == '-')
		sign = -1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while ((str[index] != '\0') && (ft_isdigit(str[index])))
	{
		result = (result * 10) + (str[index] - '0');
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483648 && sign == -1)
			return (0);
		index++;
	}
	return (sign * result);
}

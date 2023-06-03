/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:11:58 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/02 17:12:07 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

void	ft_putstr_fd(char *str, int file_descriptor)
{
	while (*str)
	{
		write(file_descriptor, str++, 1);
	}
}

void	ft_putnbr_fd(int integer, int file_descriptor)
{
	char			digit;
	unsigned int	num;

	num = integer;
	if (integer < 0)
	{
		write(file_descriptor, "-", 1);
		num = -integer;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, file_descriptor);
	}
	digit = num % 10 + '0';
	write(file_descriptor, &digit, 1);
}

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

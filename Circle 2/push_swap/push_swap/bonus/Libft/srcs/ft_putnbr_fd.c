/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:54:03 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 04:18:28 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int integer, int file_descriptor)
{
	unsigned int	num;

	num = integer;
	if (integer < 0)
	{
		ft_putchar_fd('-', file_descriptor);
		num = -integer;
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, file_descriptor);
	}
	ft_putchar_fd(num % 10 + '0', file_descriptor);
}

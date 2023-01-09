/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:53:56 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 15:26:00 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int file_descriptor)
{
	while (*str != '\0')
	{
		write(file_descriptor, str, 1);
		str ++;
	}
	write(file_descriptor, "\n", 1);
}

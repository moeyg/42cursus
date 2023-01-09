/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:56:20 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 13:38:48 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int ascii_num)
{
	if ('a' <= ascii_num && ascii_num <= 'z')
	{
		ascii_num -= 32;
	}
	return (ascii_num);
}

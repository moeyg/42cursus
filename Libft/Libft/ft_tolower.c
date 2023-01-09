/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:56:17 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 13:38:09 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int ascii_num)
{
	if ('A' <= ascii_num && ascii_num <= 'Z')
	{
		ascii_num += 32;
	}
	return (ascii_num);
}

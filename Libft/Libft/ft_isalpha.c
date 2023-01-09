/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:49:41 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/08 13:06:31 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int ascii_num)
{
	if (('a' <= ascii_num && ascii_num <= 'z')
		|| ('A' <= ascii_num && ascii_num <= 'Z'))
		return (1);
	return (0);
}

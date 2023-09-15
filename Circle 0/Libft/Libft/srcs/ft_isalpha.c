/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:49:41 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/15 21:01:48 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int code_point)
{
	if (('a' <= code_point && code_point <= 'z')
		|| ('A' <= code_point && code_point <= 'Z'))
	{
		return (1);
	}
	return (0);
}

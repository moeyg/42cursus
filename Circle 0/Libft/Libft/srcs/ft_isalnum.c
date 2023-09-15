/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:49:34 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/15 21:01:48 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int code_point)
{
	if (ft_isalpha(code_point) || ft_isdigit(code_point))
	{
		return (1);
	}
	return (0);
}

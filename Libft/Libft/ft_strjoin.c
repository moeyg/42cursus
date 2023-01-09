/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:55:17 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/09 19:01:35 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	size_t	prefix_length;
	size_t	suffix_length;
	char	*result;

	if (prefix == NULL || suffix == NULL)
		return (0);
	prefix_length = ft_strlen(prefix);
	suffix_length = ft_strlen(suffix);
	result = (char *)malloc(prefix_length + suffix_length + 1);
	if (result == NULL)
		return (0);
	ft_strlcpy(result, prefix, prefix_length + 1);
	ft_strlcat(result, suffix, prefix_length + suffix_length + 1);
	return (result);
}

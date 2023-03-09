/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:16 by dogpark           #+#    #+#             */
/*   Updated: 2023/01/13 16:47:19 by dogpark          ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:16 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 06:00:19 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char *prefix, char *suffix)
{
	size_t	prefix_length;
	size_t	suffix_length;
	char	*result;

	if (suffix == NULL)
		return (0);
	else if (prefix == NULL && suffix != NULL)
	{
		return (ft_strdup(suffix));
	}
	prefix_length = ft_strlen(prefix);
	suffix_length = ft_strlen(suffix);
	result = (char *)malloc(prefix_length + suffix_length + 1);
	if (result == NULL)
		return (0);
	ft_strlcpy(result, prefix, prefix_length + 1);
	ft_strlcat(result, suffix, prefix_length + suffix_length + 1);
	free(prefix);
	return (result);
}

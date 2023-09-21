/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:37:07 by wyoon             #+#    #+#             */
/*   Updated: 2023/09/19 20:46:22 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*result;
	char	*p_result;
	char	*p_s1;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(result))
	{
		free(s1);
		return (NULL);
	}
	p_result = result;
	p_s1 = s1;
	while (*p_s1)
		*p_result++ = *p_s1++;
	while (*s2)
		*p_result++ = *s2++;
	*p_result = '\0';
	free(s1);
	return (result);
}

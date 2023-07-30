/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:58:42 by dogpark           #+#    #+#             */
/*   Updated: 2023/03/16 15:01:40 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t dest_size);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *prefix, char *suffix);

char	*get_next_line(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 19:42:24 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/02 19:42:29 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *str, int file_descriptor);
void	ft_putnbr_fd(int integer, int file_descriptor);
int		ft_atoi(const char *str);

#endif

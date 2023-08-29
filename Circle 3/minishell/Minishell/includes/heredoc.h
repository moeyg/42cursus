/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 23:17:09 by dogpark           #+#    #+#             */
/*   Updated: 2023/08/11 23:42:27 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

/* heredoc_utils.c */
char	*process_dollars(char *prompt);
int		heredoc_exit(char *limiter, char *filename);

/* heredoc.c */
int		setup_heredoc(char *prompt);
char	*parse_limiter(char *prompt, int *limiter_length);
char	*extract_limiter(char *prompt, int length, int *i, int quote);
void	write_heredoc(char *limiter, char *filename);

#endif

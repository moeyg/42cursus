/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:58:23 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 06:33:41 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_elem	*push_back(t_node *list, int fd)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (new == NULL)
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	new->fd = fd;
	new->data = NULL;
	if (list->head == NULL)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		list->tail -> next = new;
		new->prev = list->tail;
		list->tail = new;
	}
	return (new);
}

t_elem	*find_node(t_node *list, int fd)
{
	t_elem	*node;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	node = list->head;
	while (node != 0)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = push_back(list, fd);
	if (node == NULL)
		return (NULL);
	return (node);
}

void	delete_node(t_node *list, t_elem *backup)
{
	if (backup == NULL)
		return ;
	if (backup->prev != NULL)
		backup->prev->next = backup->next;
	else
		list->head = backup->next;
	if (backup->next != NULL)
		backup->next -> prev = backup->prev;
	else
		list->tail = backup->prev;
	free(backup->data);
	free(backup);
}

char	*merge_string(char *dest, char *src, ssize_t read_byte)
{
	ssize_t	dest_len;
	char	*str;

	dest_len = 0;
	while (dest && dest[dest_len])
		dest_len++;
	str = malloc(sizeof(char) * dest_len + read_byte + 1);
	if (!str)
	{
		free(src);
		return (0);
	}
	ft_strncpy(str, dest, dest_len);
	ft_strncpy(str + dest_len, src, read_byte);
	return (str);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	index;

	if (!dest && !src)
		return (dest);
	index = 0;
	while (index < n)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

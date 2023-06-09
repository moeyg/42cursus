/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:58:23 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 06:23:59 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_next_line(int fd)
{
	static t_node	node;
	t_elem			*backup;
	size_t			length;
	ssize_t			read_byte;

	if (BUFFER_SIZE <= 0)
		return (0);
	backup = find_node(&node, fd);
	if (!backup)
		return (NULL);
	while (1)
	{
		length = search_index(backup->data, '\n');
		if (length > 0)
			return (get_result(&node, backup, length, 0));
		read_byte = read_buffer(backup, fd);
		if (read_byte <= 0)
			return (get_newline(&node, backup, read_byte));
	}
}

size_t	search_index(char *str, char ch)
{
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		if (str[index] == ch)
			return (index + 1);
		index++;
	}
	if (ch == '\0')
		return (index + 1);
	return (0);
}

char	*get_result(t_node *node, t_elem *backup, size_t len, size_t data)
{
	char	*result;
	char	*temp;

	while (backup -> data && backup->data[data])
		data++;
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
	{
		delete_node(node, backup);
		return (0);
	}
	ft_strncpy(result, backup -> data, len);
	temp = backup -> data;
	backup -> data = malloc(sizeof(char) * (data - len + 1));
	if (backup -> data == 0)
	{
		free (result);
		backup -> data = temp;
		delete_node(node, backup);
		return (0);
	}
	ft_strncpy(backup -> data, temp + len, data - len);
	free(temp);
	return (result);
}

char	*get_newline(t_node *node, t_elem *backup, ssize_t read_byte)
{
	char	*result;
	ssize_t	data;

	data = 0;
	while (backup -> data && backup -> data[data])
		data++;
	if (read_byte < 0 || data == 0)
	{
		delete_node(node, backup);
		return (NULL);
	}
	result = malloc(sizeof(char) * (data + 1));
	if (result == NULL)
	{
		delete_node(node, backup);
		return (NULL);
	}
	ft_strncpy(result, backup -> data, data);
	delete_node(node, backup);
	return (result);
}

ssize_t	read_buffer(t_elem *backup, int fd)
{
	char	*buffer;
	char	*temp;
	ssize_t	read_byte;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (-1);
	while (1)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte <= 0)
			break ;
		temp = backup -> data;
		backup -> data = merge_string(backup -> data, buffer, read_byte);
		if (backup -> data == 0)
		{
			backup -> data = temp;
			return (-1);
		}
		free (temp);
		if (search_index(backup -> data, '\n') != 0)
			break ;
	}
	free(buffer);
	return (read_byte);
}
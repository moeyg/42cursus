#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *backup);
static char	*parse_line(char *backup);
static char	*update_line(char *backup);
static char	*ft_strchr(const char *str, int ascii_num);

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
	{
		return (0);
	}
	backup[fd] = read_line(fd, backup[fd]);
	if (backup[fd] == NULL)
	{
		return (0);
	}
	next_line = parse_line(backup[fd]);
	backup[fd] = update_line(backup[fd]);
	return (next_line);
}

static char	*read_line(int fd, char *backup)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (0);
	bytes_read = 1;
	while (ft_strchr(backup, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(backup);
			return (0);
		}
		buffer[bytes_read] = 0;
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

static char	*parse_line(char *backup)
{
	char	*parsed_line;
	size_t	index;

	if (backup[0] == '\0')
		return (0);
	index = 0;
	while (backup[index] && backup[index] != '\n')
		index ++;
	parsed_line = (char *)malloc(index + 2);
	if (parsed_line == NULL)
		return (0);
	index = 0;
	while (backup[index] != '\0' && backup[index] != '\n')
	{
		parsed_line[index] = backup[index];
		index ++;
	}
	if (backup[index] == '\n')
	{
		parsed_line[index] = backup[index];
		index ++;
	}
	parsed_line[index] = 0;
	return (parsed_line);
}

static char	*update_line(char *backup)
{
	char	*updated_line;
	int		newline_index;
	int		copy_length;

	newline_index = 0;
	while (backup[newline_index] && backup[newline_index] != '\n')
		newline_index ++;
	if (backup[newline_index] == '\0')
	{
		free(backup);
		return (0);
	}
	updated_line = (char *)malloc(ft_strlen(backup) - ++newline_index + 1);
	if (updated_line == NULL)
	{
		free(backup);
		return (0);
	}
	copy_length = ft_strlen(backup) - newline_index + 1;
	ft_strlcpy(updated_line, backup + newline_index, copy_length);
	free(backup);
	return (updated_line);
}

static char	*ft_strchr(const char *str, int ascii_num)
{
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		if (*str == (char)ascii_num)
			return ((char *)str);
		str ++;
	}
	if (ascii_num == 0)
		return ((char *)str);
	return (0);
}

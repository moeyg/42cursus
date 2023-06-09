/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:56:45 by dogpark           #+#    #+#             */
/*   Updated: 2023/06/10 06:28:38 by moeyg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

# define BUFFER_SIZE 10000
# define OPEN_MAX 10240

# define BASE_UPPERCASE "0123456789ABCDEF"
# define BASE_LOWERCASE "0123456789abcdef"

typedef struct s_elem
{
	struct s_elem		*next;
	struct s_elem		*prev;
	char				*data;
	int					fd;
}	t_elem;

typedef struct s_node
{
	t_elem	*head;
	t_elem	*tail;
}	t_node;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* Character management function */
int		ft_isalpha(int ascii_num);
int		ft_isdigit(int ascii_num);
int		ft_isalnum(int ascii_num);
int		ft_isascii(int ascii_num);
int		ft_isprint(int ascii_num);
int		ft_toupper(int ascii_num);
int		ft_tolower(int ascii_num);

/* String function */
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t	ft_strlcat(char *dest, const char *src, size_t dest_size);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strchr(const char *str, int ascii_num);
char	*ft_strrchr(const char *str, int ascii_num);
char	*ft_strnstr(const char *str, const char *content, size_t length);
char	*ft_strdup(const char *str);
char	*ft_strmapi(char const *str, char (*func)(unsigned int, char));
void	ft_striteri(char *str, void (*func)(unsigned int, char*));

int		ft_atoi(const char *str);
char	*ft_itoa(int integer);

char	*ft_substr(char const *str, unsigned int start, size_t length);
char	*ft_strjoin(char *prefix, char *suffix);
char	*ft_strtrim(char const *str, char const *delete);
char	**ft_split(char const *str, char delimiter);

/* Memory function */
void	*ft_memset(void *ptr, int value, size_t length);
void	*ft_memcpy(void *dest, const void *src, size_t length);
void	*ft_memmove(void *dest, const void *src, size_t length);
void	*ft_memchr(const void *ptr, int value, size_t length);
int		ft_memcmp(const void *str1, const void *str2, size_t length);

void	ft_bzero(void *str, size_t size);
void	*ft_calloc(size_t count, size_t size);

/* File descriptor function */
void	ft_putchar_fd(char character, int file_descriptor);
void	ft_putstr_fd(char *str, int file_descriptor);
void	ft_putendl_fd(char *str, int file_descriptor);
void	ft_putnbr_fd(int integer, int file_descriptor);

/* List function */
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *list);
int		ft_lstsize(t_list *list);
void	ft_lstadd_front(t_list **list, t_list *new);
void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_lstdelone(t_list *list, void (*del)(void *));
void	ft_lstclear(t_list **list, void (*del)(void *));
void	ft_lstiter(t_list *list, void (*func)(void *));
t_list	*ft_lstmap(t_list *list, void *(*func)(void *), void (*del)(void *));

/* get_next_line */
char	*get_next_line(int fd);
size_t	search_index(char *str, char ch);
ssize_t	read_buffer(t_elem *backup, int fd);
char	*get_result(t_node *node, t_elem *backup, size_t len, size_t data);
char	*get_newline(t_node *node, t_elem *backup, ssize_t read_byte);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*merge_string(char *s1, char *s2, ssize_t read_byte);
void	delete_node(t_node *list, t_elem *backup);
t_elem	*push_back(t_node *list, int fd);
t_elem	*find_node(t_node *list, int fd);

/* ft_printf */
int		ft_printf(const char *format, ...);
void	print_char(char character, int *count);
void	print_string(char *string, int *count);
void	print_int(int integer, int *count);
void	print_unsigned_int(unsigned int integer, int *count);
void	print_hexadecimal(char specifier, unsigned long hex, int *count);

#endif

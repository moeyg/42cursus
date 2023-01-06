#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}   t_list;

int     ft_isalpha(int ascii_num);
int     ft_isdigit(int ascii_num);
int     ft_isalnum(int ascii_num);
int	    ft_isascii(int ascii_num);
int     ft_isprint(int ascii_num);
int     ft_toupper(int ascii_num);
int     ft_tolower(int ascii_num);

size_t  ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t	ft_strlcat(char *dest, const char *src, size_t dest_size);
int     ft_strncmp(const char *str1, const char *str2, size_t length);
char	*ft_strchr(const char *str, int ascii_num);
char    *ft_strrchr(const char *str, int ascii_num);
char	*ft_strnstr(const char *str, const char *content, size_t length);
char    *ft_strdup(const char *str);

int     ft_atoi(const char *str);

void    *ft_memset(void *ptr, int value, size_t length);
void    *ft_memcpy(void *dest, const void *src, size_t length);
void    *ft_memmove(void *dest, const void *src, size_t length);
void    *ft_memchr(const void *ptr, int value, size_t length);
int     ft_memcmp(const void *str1, const void *str2, size_t length);

void    ft_bzero(void *str, size_t size);
void    *ft_calloc(size_t count, size_t size);

char    *ft_substr(char const *str, unsigned int start, size_t length);
char    *ft_strjoin(char const *prefix, char const *suffix);
char	*ft_strtrim(char const *str, char const *delete);
char    **ft_split(char const *str, char delimiter);

void    ft_putchar_fd(char character, int file_descriptor);
void    ft_putstr_fd(char *str, int file_descriptor);
void    ft_putendl_fd(char *str, int file_descriptor);
void    ft_putnbr_fd(int integer, int file_descriptor);

int 	ft_lstsize(t_list *list);
t_list  *ft_lstnew(void *content);
t_list  *ft_lstlast(t_list *list);
void    ft_lstadd_front(t_list **list, t_list *new);

#endif
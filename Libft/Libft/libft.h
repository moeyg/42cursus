#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

// struct
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


int     ft_atoi(const char *str);
void    ft_bzero(void *str, size_t size);

void    *ft_memset(void *ptr, int value, size_t length);
void    *ft_memcpy(void *dest, const void *src, size_t length);
void    *ft_memmove(void *dest, const void *src, size_t length);
void    *ft_memchr(const void *ptr, int value, size_t length);
int     ft_memcmp(const void *str1, const void *str2, size_t length);


#endif
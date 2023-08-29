# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 02:16:40 by wyoon             #+#    #+#              #
#    Updated: 2023/08/12 01:59:21 by wyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Werror -Wextra -Wall

AR = ar
ARFLAGS = rcs

RM = rm
RMFALGS = -rf

HEADER = -I../includes

SRCS = 	ft_isalpha.c ft_isalnum.c ft_isprint.c ft_atoi.c ft_isdigit.c 	\
	   	ft_isascii.c ft_bzero.c ft_memset.c ft_memcmp.c ft_memcpy.c 	\
	   	ft_memmove.c ft_memchr.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
	   	ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlen.c 	\
	   	ft_calloc.c ft_strdup.c ft_strnstr.c ft_strjoin.c ft_substr.c 	\
	   	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c 	\
	   	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 	\
		ft_printf.c	ft_printf_format.c get_next_line.c ft_strcmp.c		\
		get_next_line_utils.c ft_isspace.c								\

OBJS = $(SRCS:.c=.o)

all	: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

clean : 
		$(RM) $(RMFALGS) $(OBJS)

fclean : clean
		$(RM) $(RMFALGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 13:51:37 by dogpark           #+#    #+#              #
#    Updated: 2023/01/16 17:25:11 by moeyg            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER  = ./libft.h
SRCS = 	\
		./ft_isalpha.c \
		./ft_isdigit.c \
		./ft_isalnum.c \
		./ft_isascii.c \
		./ft_isprint.c \
		./ft_toupper.c \
		./ft_tolower.c \
		./ft_strlen.c \
		./ft_strlcpy.c \
		./ft_strlcat.c \
		./ft_strncmp.c \
		./ft_strchr.c \
		./ft_strrchr.c \
		./ft_strnstr.c \
		./ft_strdup.c \
		./ft_strmapi.c \
		./ft_striteri.c \
		./ft_atoi.c \
		./ft_itoa.c \
		./ft_substr.c \
		./ft_strjoin.c \
		./ft_strtrim.c \
		./ft_split.c \
		./ft_memset.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_bzero.c \
		./ft_calloc.c \
		./ft_putchar_fd.c \
		./ft_putstr_fd.c \
		./ft_putendl_fd.c \
		./ft_putnbr_fd.c


OBJS = $(SRCS:.c=.o)

SRCS_BONUS =	\
				./ft_lstnew.c \
				./ft_lstlast.c \
				./ft_lstsize.c \
				./ft_lstadd_front.c \
				./ft_lstadd_back.c \
				./ft_lstdelone.c \
				./ft_lstclear.c \
				./ft_lstiter.c \
				./ft_lstmap.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS
	OBJS_F = $(OBJS) $(OBJS_BONUS)
else
	OBJS_F = $(OBJS)
endif

all : $(NAME)

.c.o : $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS_F)
	ar rc $(NAME) $(OBJS_F)

bonus :
	make BONUS=1 all

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY : all bonus clean fclean re

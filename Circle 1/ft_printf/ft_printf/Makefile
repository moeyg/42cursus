# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dogpark <dogpark@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 19:42:21 by dogpark           #+#    #+#              #
#    Created: 2023/03/29 19:49:21 by dogpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAG = -Wall -Wextra -Werror

COMPILE = $(CC) $(CFLAG) -c $< -o $@ -I ${INCLUDES_DIRECTORY}

NAME = libftprintf.a

INCLUDES_DIRECTORY  = includes

SRCS_DIRECTORY = srcs

SRCS = $(addprefix $(SRCS_DIRECTORY)/, ft_printf.c print_format.c)

OBJECTS = $(SRCS:.c=.o)

%.o: %.c ${INCLUDES_DIRECTORY}
	$(COMPILE)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)
	
re : fclean all

.PHONY:	all clean fclean re

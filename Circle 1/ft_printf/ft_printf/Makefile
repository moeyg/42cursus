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

# Compiler
CC = cc

# Compiler flag
CFLAG = -Wall -Wextra -Werror

# Compile command line
COMPILE = $(CC) $(CFLAG) -c $< -o $@ -I ${INCLUDES_DIRECTORY}

# Library name
NAME = libftprintf.a

# Header file directory
INCLUDES_DIRECTORY  = includes

# Source directory
SRCS_DIRECTORY = srcs

# Source files
SRCS =  $(addprefix ${SRCS_DIRECTORY}/,	\
			./ft_printf.c \
			./print_format.c)

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

.PHONY:	all bonus clean fclean re

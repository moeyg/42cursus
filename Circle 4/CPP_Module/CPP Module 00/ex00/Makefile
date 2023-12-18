# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 18:34:53 by dogpark           #+#    #+#              #
#    Updated: 2023/12/17 22:41:44 by dogpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CPP = c++

# Complie flag
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

# SRCS
SRCS = megaphone.cpp

# OBJECTS
OBJECTS = $(SRCS:.cpp=.o)

# Library name
NAME = megaphone

all = $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(NAME) $(OBJECTS)

re: fclean all

.PHONY: all clean fclean re
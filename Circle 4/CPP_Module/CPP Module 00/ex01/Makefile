# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 19:22:28 by dogpark           #+#    #+#              #
#    Updated: 2023/12/18 01:49:42 by dogpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CPP = c++

# Complie flag
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

# SRCS
SRCS = main.cpp \
	   PhoneBook.cpp \
	   Contact.cpp \

# OBJECTS
OBJECTS = $(SRCS:.cpp=.o)

# Library name
NAME = phonebook

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
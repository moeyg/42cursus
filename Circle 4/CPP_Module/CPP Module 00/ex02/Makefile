# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 14:31:25 by dogpark           #+#    #+#              #
#    Updated: 2023/12/18 14:31:26 by dogpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CPP = c++

# Compile flag
CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

# SRCS
SRCS    = Account.cpp \
		  tests.cpp \

# OBJECTS
OBJECTS	= $(SRCS:.cpp=.o)

# Library name
NAME    = account

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f  $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
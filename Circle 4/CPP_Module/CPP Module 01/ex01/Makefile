# Compiler
CPP = c++

# Complie flag
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

# SRCS
SRCS = main.cpp \
	   Zombie.cpp \
	   ZombieHorde.cpp \

# OBJECTS
OBJECTS = $(SRCS:.cpp=.o)

# Library name
NAME = zombieHorde

all: $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean:
	rm -rf $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
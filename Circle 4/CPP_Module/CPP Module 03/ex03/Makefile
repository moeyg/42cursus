# Compiler
CPP = c++

# Complie flag
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

# SRCS
SRCS = main.cpp \
	   ClapTrap.cpp \
	   ScavTrap.cpp \
	   FragTrap.cpp \
	   DiamondTrap.cpp \

# OBJECTS
OBJECTS = $(SRCS:.cpp=.o)

# Library name
NAME = diamondTrap

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
CHECK = \033[0;32m\xE2\x9C\x94\033[0m

all: $(NAME)

$(NAME) : $(OBJECTS)
	@echo "$(NAME): $(GREEN) compiling... $< $(CHECK) $(RESET)"
	$(CPP) $(CPP_FLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(NAME): $(GREEN) $(NAME) has been complied. $(CHECK) $(RESET)"

clean:
	rm -rf $(OBJECTS)
	@echo "$(NAME): $(RED) Object files were deleted. $(RESET)"

fclean:
	rm -rf $(OBJECTS) $(NAME)
	@echo "$(NAME): $(RED) $(NAME) was deleted. $(RESET)"

re: fclean all

.PHONY: all clean fclean re
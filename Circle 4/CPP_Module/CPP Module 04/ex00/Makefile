# Compiler
CPP = c++

# Complie flag
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98

# SRCS
SRCS = main.cpp \
	   Animal.cpp \
	   Cat.cpp \
	   Dog.cpp \
	   WrongAnimal.cpp \
	   WrongCat.cpp \

# OBJECTS
OBJECTS = $(SRCS:.cpp=.o)

# Library name
NAME = animal

# Color
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
CHECK = \033[0;32m\xE2\x9C\x94\033[0m

%.o: %.cpp
	@$(CPP) $(CPP_FLAGS) -c $< -o $@ -I.
	@echo "$(NAME): $(GREEN) compiling... $< $(CHECK) $(RESET)"

all: $(NAME)

$(NAME) : $(OBJECTS)
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
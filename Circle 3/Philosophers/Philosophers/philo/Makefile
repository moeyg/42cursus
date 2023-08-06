# Compiler
CC = cc

# Compiler flag
CFLAGS = -Wall -Wextra -Werror

# File directory
INCLUDES_DIRECTORY = includes
SRCS_DIRECTORY = srcs

# Library name
NAME = philo

RED = \033[0;31m

# SRCS
SRCS = $(addprefix $(SRCS_DIRECTORY)/, \
		main.c \
		initialize.c \
		time_utils.c \
		utils.c \
		status.c)

OBJECTS = $(SRCS:.c=.o)

# Build the main target
all : $(NAME)

# Rule of compile source files to object files
%.o: %.c ${INCLUDES_DIRECTORY} $(SRCS) $(CC) $(CFLAGS) -c -o $@ $^

# Rule of build the final target
$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

norm :
	norminette includes/*.h srcs/*.c
	@echo "$(RED)Completed norminette"

clean :
	rm -f $(OBJECTS)
	@echo "$(RED)Delete: Object files"

fclean : clean
	rm -f $(NAME)
	@echo "$(RED)Delete: $(NAME)"

# Rule to perform a clean build
re : fclean all

# Declare the phony targets (targets that are not associated with files)
.PHONY : all norm clean fclean re
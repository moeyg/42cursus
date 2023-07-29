# Compiler
CC = cc

# Compiler flag
CFLAGS = -Wall -Wextra -Werror

# File directory
INCLUDES_DIRECTORY = includes
SRCS_DIRECTORY = srcs

# Library name
NAME = fractol

# MiniLibx library
libmlx = ./mlx/libmlx.a

RED = \033[0;31m

# SRCS
SRCS = $(addprefix $(SRCS_DIRECTORY)/, \
		fractol.c \
		draw_fractol.c \
		calculate_fractol.c \
		key_events.c \
		mouse_events.c \
		utils.c \
		setting.c)

OBJECTS = $(SRCS:.c=.o)
OBJECTS_FINAL_VERSION = $(OBJECTS)

# Build the main target
all : $(NAME)

# Rule of compile source files to object files
%.o: %.c ${INCLUDES_DIRECTORY} $(SRCS) $(CC) -c -o $@ $^

# Rule of build the final target
$(NAME) : $(libmlx) $(OBJECTS_FINAL_VERSION)
		ar rc $(NAME) $(libmlx) $(OBJECTS_FINAL_VERSION)
		ranlib $(NAME)
	@$(CC) -o $(NAME) $(OBJECTS_FINAL_VERSION) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

# Rule to build the MiniLibx
$(libmlx):
	@$(MAKE) -sC ./mlx/

# Rule to clean the objects files
clean :
	@$(MAKE) -sC ./mlx/ clean
	@rm -f $(OBJECTS)

# Rule to clean all generated files
fclean : clean
	rm -f $(libmlx)
	rm -f $(NAME)
	@echo "$(NAME): $(RED)object files were deleted"
	@echo "$(NAME): $(RED)$(libmlx) was deleted"
	@echo "$(NAME): $(RED)$(NAME) was deleted"

# Rule to perform a clean build
re : fclean all

# Declare the phony targets (targets that are not associated with files)
.PHONY : all clean fclean re

# Compiler
CC = cc

# Compiler flag
CFLAGS = -Wall -Wextra -Werror -O3

# File directory
INCLUDES_DIRECTORY = includes
SRCS_DIRECTORY = srcs
SRCS_BONUS_DIRECTORY = srcs_bonus

# Library name
NAME = fractol

# MiniLibx library
libmlx = ./mlx/libmlx.a

RED = \033[0;31m
RESET = \033[0m

# SRCS
SRCS = $(addprefix $(SRCS_DIRECTORY)/, \
		fractol.c \
		draw_fractol.c \
		calculate_fractol.c \
		key_events.c \
		mouse_events.c \
		utils.c \
		setting.c)

# SRCS_BONUS
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIRECTORY)/, \
		fractol_bonus.c \
		draw_fractol_bonus.c \
		calculate_fractol_bonus.c \
		key_events_bonus.c \
		mouse_events_bonus.c \
		utils_bonus.c \
		setting_bonus.c)

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS
	OBJECTS_FINAL_VERSION = $(OBJECTS) $(OBJECTS_BONUS)
else
	OBJECTS_FINAL_VERSION = $(OBJECTS)
endif

# Build the main target
all : $(NAME)

# Rule of compile source files to object files
%.o: %.c ${INCLUDES_DIRECTORY} $(SRCS) $(CC) -c -o $@ $^

# Rule of build the final target
$(NAME) : $(libmlx) $(OBJECTS_FINAL_VERSION)
		ar rc $(NAME) $(libmlx) $(OBJECTS_FINAL_VERSION)
		ranlib $(NAME)
	@$(CC) -o $(NAME) $(OBJECTS) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit

# Rule to build the MiniLibx
$(libmlx):
	@$(MAKE) -sC ./mlx/

# Rule to build the bonus target
bonus:
	$(MAKE) BONUS=1 all

# Rule to clean the objects files
clean :
	@$(MAKE) -sC ./mlx/ clean
	@rm -f $(OBJECTS) $(OBJECTS_BONUS)	

# Rule to clean all generated files
fclean : clean
	rm -f $(libmlx)
	rm -f $(NAME)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@echo "$(NAME): $(RED)$(libmlx) was deleted$(RESET)"
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

# Rule to perform a clean build
re : fclean all

# Declare the phony targets (targets that are not associated with files)
.PHONY : all bonus clean fclean re
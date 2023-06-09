# Compiler
CC = cc

# Compiler flag
CFLAGS = -Wall -Werror -Wextra

OBJECTS = \
        compare_rotations.c \
        deque.c \
        find_operations.c \
        free_operations.c \
        get_operations.c \
        greedy.c \
        initialization_operations.c \
        main.c \
        ops_push.c \
        ops_reverse_rotate.c \
        ops_rotate.c \
        ops_swap.c \
        rotate_stacks.c \
        sort_operations.c \
        validate_stack.c

OBJECTS_CHECKER = \
        build_stack.c \
        check_operation.c \
        checker.c \
        deque.c \
        free_operations.c \
        initialization_stack.c \
        ops_push.c \
        ops_reverse_rotate.c \
        ops_rotate.c \
        ops_swap.c \
        validate_stack.c

SRCS = $(addprefix mandatory/, $(OBJECTS))
SRCS_BONUS = $(addprefix bonus/, $(OBJECTS_CHECKER))
SRCS_FILES = $(SRCS:.c=.o)
SRCS_BONUS_FILES = $(SRCS_BONUS:.c=.o)

MAND_DIR = mandatory
BONUS_DIR = bonus

NAME = push_swap
BONUS = checker
RM = rm -rf

%.o: %c
	@$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(SRCS_FILES)
	@make -C ./mandatory/libft all
	@echo "Compiling push_swap.."
	@$(CC) $(CFLAGS) ./mandatory/libft/libft.a -o $@ $^
	@echo "Compiled push_swap"

$(BONUS) : $(SRCS_BONUS_FILES)
	@make -C ./bonus/libft all
	@echo "Compiling bonus.."
	@$(CC) $(CFLAGS) ./bonus/libft/libft.a -o $@ $^
	@echo "Compiled bonus"

libft :
	@make -C ./mandatory/mendatory/libft
	@make -C ./mandatory/bonus/libft

all : 
	@make $(NAME)

bonus : 
	@make $(BONUS)

clean :
	@make -C ./mandatory/libft clean
	@make -C ./bonus/libft clean
	@$(RM) $(SRCS_FILES)
	@$(RM) $(SRCS_BONUS_FILES)
	@echo "Delete object files"

fclean : clean
	@make -C ./mandatory/libft fclean
	@make -C ./bonus/libft fclean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@echo "Delete all files"

re :
	@make fclean
	@make all

.PHONY: all clean fclean re bonus

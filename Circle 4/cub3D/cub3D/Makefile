# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 20:01:49 by dogpark           #+#    #+#              #
#    Updated: 2023/09/21 19:30:33 by dogpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = cc

# Compile flags
CFLAGS = -Wall -Werror -Wextra
LFLAGS =  -L ./srcs/mlx -lmlx -framework OpenGL -framework Appkit

# Program name
NAME = cub3d

# Remove files flag
RM = rm -rf

# SRCS
SRCS =	main.c					\
		initialize.c			\
		read_map.c				\
		map_parsing.c			\
		map_rendering.c			\
		raycasting.c			\
		initialize_raycasting.c	\
		setting_raycasting.c	\
		setting_color.c			\
		setting_environment.c	\
		key_events.c			\
		validate.c				\
		free_memory.c			\
		exit_cub3d.c			\

SRCS_DIR = srcs/cub3d/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

# LIBFT
LIBFT_DIR = srcs/libft/
LIBFT_A = $(addprefix $(LIBFT_DIR), libft.a)

# MLX
MLX_DIR = srcs/mlx
MLX_PATH = $(addprefix, $(MLX_DIR), libmlx.a)

# INCLUDES
INCS = includes/
OBJS = $(SRCS_PATH:.c=.o)

# Memory leaks
ifdef sanitize
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
endif

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCS) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C srcs/libft
	@make -C srcs/mlx
	@$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A)

clean:
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS) $(B_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(MLX_DIR) clean
	@$(RM) $(NAME)

re:
	@make fclean
	@make all

sanitize:
	@make sanitize=1 re

bonus: $(NAME)

.PHONY: all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m

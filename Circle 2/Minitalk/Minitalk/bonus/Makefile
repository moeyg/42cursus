# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moeyg <moeyg@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/02 17:14:10 by dogpark           #+#    #+#              #
#    Updated: 2023/07/30 21:13:22 by moeyg            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc

# Compiler flag
CFLAGS = -Wall -Wextra -Werror

# File directory
INCLUDES_DIRECTORY = includes
SRCS_DIRECTORY = srcs

# Compile command line
COMPILE = $(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES_DIRECTORY)

# Library name
NAME = minitalk
SERVER = server
CLIENT = client

# SERVER srcs
SERVER_SRCS = $(addprefix $(SRCS_DIRECTORY)/, server_bonus.c utils_bonus.c)

# CLIENT srcs
CLIENT_SRCS =  $(addprefix $(SRCS_DIRECTORY)/, client_bonus.c utils_bonus.c)

# SERVER objs
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# CLIENT objs
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all: $(NAME) $(SERVER) $(CLIENT)

%.o: %.c ${INCLUDES_DIRECTORY}
		$(COMPILE)

$(NAME): $(SERVER_OBJS) $(CLIENT_OBJS)
		ar rc $(NAME) $(SERVER_OBJS) $(CLIENT_OBJS)
		ranlib $(NAME)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_BONUS_OBJS) $(CLIENT_BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re

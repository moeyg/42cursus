# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wyoon <wyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 02:12:55 by dogpark           #+#    #+#              #
#    Updated: 2023/08/12 02:00:16 by wyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Werror -Wall -Wextra

RM = rm
RMFALGS = -rf

RL_LIB = -lreadline -L$(HOME)/.brew/opt/readline/lib
RL_INC = -I$(HOME)/.brew/opt/readline/include

HEADER = -I./includes

SRCS = ./srcs/main.c ./srcs/append_env.c ./srcs/builtin.c 						\
	./srcs/cd.c	./srcs/cd_utils.c												\
	./srcs/command_execution.c ./srcs/command_management.c ./srcs/command.c		\
	./srcs/env_handler.c ./srcs/env_setting.c ./srcs/env_utils.c				\
	./srcs/error.c ./srcs/execution.c ./srcs/free.c								\
	./srcs/heredoc_utils.c ./srcs/heredoc.c ./srcs/initialize.c					\
	./srcs/io_redirection.c ./srcs/merge.c ./srcs/quote.c ./srcs/signal.c		\
	./srcs/space.c ./srcs/type.c												\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) -o $(NAME) $(HEADER) $(LIBFT) $(OBJS) $(RL_LIB)

%.o : %.c
			$(CC) $(CFLAGS) $(RL_INC) $(HEADER) -c $< -o $@

$(LIBFT) :
		make -C ./libft all

clean :
		make -C ./libft fclean
		$(RM) $(RMFALGS) $(OBJS)

fclean : clean
		$(RM) $(RMFALGS) $(NAME)

re :
		make fclean
		make all

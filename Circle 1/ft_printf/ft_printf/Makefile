# Compiler
CC = gcc

# Compiler flag
CFLAG = -Wall -Wextra -Werror

# Compile command line
COMPILE = $(CC) $(CFLAG) -c $< -o $@ -I ${INCLUDES_DIRECTORY}

# Library name
NAME = libftprintf.a

# Header file directory
INCLUDES_DIRECTORY  = includes

# Source directory
SRCS_DIRECTORY = srcs

# Source files
SRCS =  $(addprefix ${SRCS_DIRECTORY}/,	\
			./ft_printf.c \
			./print_format.c)

OBJECTS = $(SRCS:.c=.o)

%.o: %.c ${INCLUDES_DIRECTORY}
	$(COMPILE)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

bonus:
	make all

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)
	
re :
	make fclean

.PHONY:	all bonus clean fclean re
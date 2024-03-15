# Compiler
CPP = c++

# Complie flag
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
DB = -g3
FA = -fsanitize=address
AR = ar
ARFLAG = ruc
RM = rm -f

OBJECTS_DIRECTORY = ./objects

# Option
DELINE = \033[K
CURSUP = \033[A
RESET = \033[0m
RESTINT = \033[22m
BOLD = \033[1m
MAGENTA = \033[35m
GREEN = \033[32m
RED = \033[31m
CHECK = \033[0;32m\xE2\x9C\x94\033[0m

# Library name
NAME = ircserv

# Mandatory
SRC1 :=
SRC1 += main.cpp
SRC1 += Multiplex.cpp
SRC1 += Channel.cpp
SRC1 += FileDescriptor.cpp
SRC1 += Server.cpp
SRC1 += StringHandle.cpp
SRC1 += EventHandler.cpp
SRC1 += EventCmd.cpp
SRC1 += Bot.cpp

# Bonus
SRC2 :=
SRC2 +=

# SRCS
SRCS = $(SRC1) $(SRC2)

# OBJECTS
OBJECTS1 = $(SRC1:.cpp=.o)
OBJECTS2 = $(SRC2:.cpp=.o)
OBJECTS = $(OBJECTS1) $(OBJECTS2)

define FINAL
$(addprefix $(OBJECTS_DIRECTORY)/, $(call $(if $(filter bonus, $(MAKECMDGOALS)), OBJECTS, OBJECTS1)))
endef

define react
$(if $(filter bonus, $(MAKECMDGOALS)), bonus, all)
endef

all : $(NAME)

$(NAME) : $(FINAL)
	@$(CPP) $(CPP_FLAGS) -o $@ $(FINAL)
	@echo "$(DELINE) $(MAGENTA)$@ $(RESET) is compiled $(GREEN)$(BOLD)$(CHECK) $(RESET)"

bonus : $(NAME)

$(OBJECTS_DIRECTORY)/%.o : %.cpp
	@mkdir -p $(OBJECTS_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)/$(dir $^)
	@$(CPP) $(CPP_FLAGS) -c $^ -o $@
	@echo " $(MAGENTA)$(NAME) $(RESET)objects file compiling... $(DELINE)$(GREEN) $^ $(RESET)$(CURSUP)"

clean :
	@$(RM) $(OBJECTS)
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(RED) Delete: $(BOLD) objects $(RESTINT)file $(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@$(RM) log
	@echo "$(RED) Delete: $(BOLD) $(NAME) $(RESTINT)file $(RESET)"

re : fclean
	@make $(react)

.PHONY : clean fclean re all bonus
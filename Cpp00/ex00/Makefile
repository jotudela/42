# Compiler
CC		= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror

# Nom de l'exécutable
NAME		= megaphone

# Couleurs
RESET		:= \033[0m
BOLD		:= \033[1m
RED		:= \033[91m
GREEN		:= \033[92m

# Fichiers sources
SRC_FILES	= src/megaphone.cpp
OBJ_FILES	= $(SRC_FILES:.cpp=.o)

# Commandes
RM		= rm -f

# Règles
all: $(NAME)

%.o: %.cpp
	@echo "$(BOLD)$(RED)[Compiling $<...]$(RESET)"
	@$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	@$(CC) $(CPPFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "$(BOLD)$(GREEN)[Build complete!]$(RESET)"

clean:
	@$(RM) $(OBJ_FILES)
	@echo "$(BOLD)$(RED)[Objects removed!]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BOLD)$(RED)[Executable removed!]$(RESET)"

re: fclean all

.PHONY: all clean fclean re

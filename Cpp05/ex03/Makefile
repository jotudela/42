# Compiler
CC		= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror

# Nom de l'exécutable
NAME		= intern

# Couleurs
RESET		:= \033[0m
BOLD		:= \033[1m
RED		:= \033[91m
GREEN		:= \033[92m

# Fichiers sources
SRC_FILES	= src/main.cpp \
			src/Bureaucrat.cpp \
			src/AForm.cpp \
			src/ShrubberyCreationForm.cpp \
			src/RobotomyRequestForm.cpp \
			src/PresidentialPardonForm.cpp \
			src/Intern.cpp
OBJ_FILES	= $(SRC_FILES:.cpp=.o)

# Includes
INC			= inc/Bureacrat.hpp \
			inc/AForm.hpp \
			inc/ShrubberyCreationForm.hpp \
			inc/RobotomyRequestForm.hpp \
			inc/PresidentialPardonForm.hpp \
			inc/Intern.hpp

# Commandes
RM		= rm -f

# Règles
all: $(NAME)

%.o: %.cpp
	@echo "$(BOLD)$(RED)[Compiling $<...]$(RESET)"
	@$(CC) $(CPPFLAGS) -I INC -c $< -o $@

$(NAME): $(OBJ_FILES)
	@$(CC) $(CPPFLAGS) $(OBJ_FILES) -I INC -o $(NAME)
	@echo "$(BOLD)$(GREEN)[Build complete!]$(RESET)"

clean:
	@$(RM) $(OBJ_FILES)
	@echo "$(BOLD)$(RED)[Objects removed!]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BOLD)$(RED)[Executable removed!]$(RESET)"

re: fclean all

.PHONY: all clean fclean re
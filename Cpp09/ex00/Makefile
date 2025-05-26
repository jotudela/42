# Compiler
CC		= c++
CPPFLAGS	= -std=c++98 -Wall -Wextra -Werror

# Nom de l'exécutable
NAME		= btc

# Couleurs
RESET		:= \033[0m
BOLD		:= \033[1m
RED		:= \033[91m
GREEN		:= \033[92m

# Fichiers sources
SRC_FILES	= src/main.cpp \
			src/BitcoinExchange.cpp
OBJ_FILES	= $(SRC_FILES:.cpp=.o)

# Includes
INC			= inc/BitcoinExchange.hpp

# Commandes
RM		= rm -f

# Règles
all: $(NAME)

%.o: %.cpp
	@echo "$(BOLD)$(RED)[Compiling $<...]$(RESET)"
	@$(CC) $(CPPFLAGS) -I INC -c $< -o $@

$(NAME): $(OBJ_FILES) file
	@$(CC) $(CPPFLAGS) $(OBJ_FILES) -I INC -o $(NAME)
	@echo "$(BOLD)$(GREEN)[Build complete!]$(RESET)"

clean:
	@$(RM) $(OBJ_FILES)
	@echo "$(BOLD)$(RED)[Objects removed!]$(RESET)"
	@$(RM) input.txt

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BOLD)$(RED)[Executable removed!]$(RESET)"

re: fclean all

file:
	@echo "date | value" > input.txt
	@echo "2011-01-03 | 3" >> input.txt
	@echo "2011-01-03 | 2" >> input.txt
	@echo "2011-01-03 | 1" >> input.txt
	@echo "2011-01-03 | 1.2" >> input.txt
	@echo "2011-01-09 | 1" >> input.txt
	@echo "2012-01-11 | 1" >> input.txt
	@echo "2010-12-31 | 0.5" >> input.txt
	@echo "2020-02-29 | 10" >> input.txt
	@echo "2012-01-11 | -1" >> input.txt
	@echo "2012-01-11 | 2147483648" >> input.txt
	@echo "2012-01-11 |" >> input.txt
	@echo "2012-01-11 | abc" >> input.txt
	@echo "2012-01-11 | 12abc34" >> input.txt
	@echo "2001-42-42" >> input.txt
	@echo "2026-01-01 | 10" >> input.txt
	@echo "2008-12-31 | 10" >> input.txt
	@echo "2011-02-30 | 1" >> input.txt
	@echo "2011-04-31 | 1" >> input.txt
	@echo "2011-13-01 | 1" >> input.txt
	@echo "2011-00-10 | 1" >> input.txt
	@echo "2011-12-00 | 1" >> input.txt
	@echo "2011-01-03|3" >> input.txt
	@echo "2011-01-03 |3" >> input.txt
	@echo "2011-01-03| 3" >> input.txt
	@echo "2011/01/03 | 3" >> input.txt
	@echo "20110103 | 3" >> input.txt
	@echo "2011-01-03 - 3" >> input.txt
	@echo "" >> input.txt
	@echo "| 3" >> input.txt
	@echo "2011-01-03 |" >> input.txt

.PHONY: all clean fclean re file
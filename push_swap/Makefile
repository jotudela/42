# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2025/01/13 14:26:53 by jotudela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= push_swap
CFLAGS		= -Wall -Wextra -Werror
CC			= cc

# Libft
LIBFT_NAME			:= libmaster.a
LIBFT_PATH			:= Utils/
UTILS				:= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC_MANDATORY		= -I inc/

###################################################
## COLORS

RESET				:= \033[0m
BOLD				:= \033[1m
RED					:= \033[91m
GREEN				:= \033[92m
YELLOW				:= \033[33m
ORANGE				:= \033[93m
BLUE				:= \033[94m

###################################################
### SOURCES

## MANDATORY PART

# SRC
SRC_FILES	= main \
			ft_init \
			ft_verif \
			ft_list \
			mouv/push \
			mouv/reverse_rotate \
			mouv/rotate \
			mouv/swap \
			logic/big_sort \
			logic/get_cost \
			logic/get_position \
			logic/move \
			logic/sort_tiny

SRC_DIR := mandatory
SRC_MANDATORY := $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))

# OBJ
OBJ_FILES	:= $(SRC_MANDATORY:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

###################################################
## RULES

all: $(UTILS) $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INC_MANDATORY) -c $< -o $@

$(UTILS):
	@make -sC $(LIBFT_PATH)
	@echo "\n\n-----------------------------------------------\n\n"

$(NAME): $(OBJ_FILES) $(UTILS)
	@echo "$(BOLD)$(RED)🛠️      Compiling push_swap    🛠️$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(UTILS) $(INC_MANDATORY) -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀      Push_swap fully compiled, ready to use       🚀$(RESET)"
	@echo "\n$(BOLD)Usage: ./push_swap 1 2 3 4 5 6 7 .....nN$(RESET)"
	@echo "\n$(BOLD)Usage: ./push_swap '1 2 3 4 5 6 7 ...nN'$(RESET)"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ_FILES)
	@rm -f $(OBJ_FILES_B)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o push_swap's files   🌀$(RESET)"

fclean: clean
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned push_swap exec       🌀$(RESET)"

re: fclean all

test2:				$(NAME)
					$(eval ARG = $(shell seq -1000 1000 | shuf -n 2))
					@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG) | wc -l > output.txt
					@echo "Instructions: "
					@sed 's/^/\t/' output.txt
					@rm output.txt

test3:				$(NAME)
					$(eval ARG = $(shell seq -1000 1000 | shuf -n 3))
					@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG) | wc -l > output.txt
					@echo "Instructions: "
					@sed 's/^/\t/' output.txt
					@rm output.txt

test5:				$(NAME)
					$(eval ARG = $(shell seq -1000 1000 | shuf -n 5))
					@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG) | wc -l > output.txt
					@echo "Instructions: "
					@sed 's/^/\t/' output.txt
					@rm output.txt

test100:			$(NAME)
					$(eval ARG = $(shell seq -1000 1000 | shuf -n 100))
					@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG) | wc -l > output.txt
					@echo "Instructions: "
					@sed 's/^/\t/' output.txt
					@rm output.txt


test500:			$(NAME)
					$(eval ARG = $(shell seq -1000 1000 | shuf -n 500))
					@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG) | wc -l > output.txt
					@echo "Instructions: "
					@sed 's/^/\t/' output.txt
					@rm output.txt


testdouble:			$(NAME)
					$(eval ARG = "1 2 3 4 5 5")
					@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG) | wc -l > output.txt
					@echo "Instructions: "
					@sed 's/^/\t/' output.txt
					@rm output.txt


testint1:			$(NAME)
					$(eval ARG = "1 deux 3 4 cinq 5")
					@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG) | wc -l > output.txt
					@echo "Instructions: "
					@sed 's/^/\t/' output.txt
					@rm output.txt


testint2:			$(NAME)
					$(eval ARG = "0 1 2 -2147483649")
					@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG) | wc -l > output.txt
					@echo "Instructions: "
					@sed 's/^/\t/' output.txt
					@rm output.txt


testint3:			$(NAME)
					$(eval ARG = "0 1 2 2147483648")
					@valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(ARG) | wc -l > output.txt
					@echo "Instructions: "
					@sed 's/^/\t/' output.txt
					@rm output.txt

.PHONY: all clean fclean re test2 test3 test5 test100 test500 testdouble testint1 testint2 testint3

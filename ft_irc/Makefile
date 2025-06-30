# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2025/06/30 21:36:58 by jojo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= ircserv
CFLAGS		= -std=c++98 -Wall -Wextra -Werror
CC			= c++

# Includes
INC_MANDATORY		= -I ./inc/

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
			Server \
			Admin \
			User

SRC_DIR := src
SRC_MANDATORY := $(addprefix $(SRC_DIR)/, $(addsuffix .cpp, $(SRC_FILES)))

# OBJ
OBJ_FILES	:= $(SRC_MANDATORY:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)

###################################################
## RULES

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) $(CFLAGS) $(INC_MANDATORY) -c $< -o $@

$(NAME): $(OBJ_FILES)
	@echo "$(BOLD)$(RED)🛠️      Compiling ircserv    🛠️$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(INC_MANDATORY) -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀      ircserv fully compiled, ready to use       🚀$(RESET)"
	@echo "\n$(BOLD)Usage: ./ircserv <port> <password>$(RESET)"

clean:
	@rm -f $(OBJ_FILES)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o ircserv's files   🌀$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned ircserv exec       🌀$(RESET)"

re: fclean all

.PHONY: all clean fclean re
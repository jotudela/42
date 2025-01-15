# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2025/01/15 16:06:45 by jotudela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror #-lmlx -lXext -lX11
CC			= cc

# Libft
LIBFT_NAME			:= libmaster.a
LIBFT_PATH			:= Utils/
UTILS				:= $(LIBFT_PATH)$(LIBFT_NAME)

# MLX
#MLX_NAME			:= libmlx.a
#MLX_PATH			:= minilibx-linux/
#MLX					:= $(MLX_PATH)$(MLX_NAME)

# Includes
INC_MANDATORY		= -I inc/# -I minilibx-linux/

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
			ft_list \
			ft_init \
			check/char_is_invalid \
			check/flood_fill \
			check/ft_control \
			check/good_len_line \
			check/good_outline \
			check/is_CEP \
			check/is_rectangle

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
	@echo "$(BOLD)$(RED)🛠️      Compiling so_long    🛠️$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(UTILS) $(INC_MANDATORY) -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀      So_long fully compiled, ready to use       🚀$(RESET)"
	@echo "\n$(BOLD)Usage: ./so_long maps/map.ber$(RESET)"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ_FILES)
	@rm -f $(OBJ_FILES_B)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o so_long's files   🌀$(RESET)"

fclean: clean
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned so_long exec       🌀$(RESET)"

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2025/01/15 16:34:31 by jotudela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror
CC			= cc

# Libft
LIBFT_NAME			:= libmaster.a
LIBFT_PATH			:= Utils/
UTILS				:= $(LIBFT_PATH)$(LIBFT_NAME)

# MLX
MLX_NAME			:= libmlx.a
MLX_PATH			:= minilibx-linux/
MLX					:= $(MLX_PATH)$(MLX_NAME)

# Includes
INC_MANDATORY		= -I ./inc/\
					-I ./minilibx-linux/

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

all: $(MLX) $(UTILS) $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INC_MANDATORY) -c $< -o $@

$(UTILS):
	@make -sC $(LIBFT_PATH)
	@echo "\n\n$(BOLD)$(BLUE)-----------------------------------------------\n\n$(RESET)"

$(MLX):
	@echo "$(BOLD)$(RED)🛠️      Compiling MiniLibX      🛠️$(RESET)"
	@echo "\n"	
	@make all -sC $(MLX_PATH)
	@echo "\n"	
	@echo "$(BOLD)$(GREEN)😎     MiniLibX Compiled    😎$(RESET)"
	@echo "\n"
	@echo "$(BOLD)$(BLUE)-----------------------------------------------$(RESET)"
	@echo "\n"

$(NAME): $(MLX) $(UTILS) $(OBJ_FILES)
	@echo "$(BOLD)$(RED)🛠️      Compiling so_long    🛠️$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(MLX) $(UTILS) $(INC_MANDATORY) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀      So_long fully compiled, ready to use       🚀$(RESET)"
	@echo "\n$(BOLD)Usage: ./so_long maps/map.ber$(RESET)"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ_FILES)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o so_long's files   🌀$(RESET)"
	@make clean -sC $(MLX_PATH)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o MiniLibX's files  🌀$(RESET)"

fclean: clean
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned so_long exec       🌀$(RESET)"

re: fclean all

.PHONY: all clean fclean re
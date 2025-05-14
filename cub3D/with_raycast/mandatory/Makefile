# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2025/05/14 11:18:26 by jotudela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= cub3D
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
			utils \
			init_and_check/ft_init \
			init_and_check/get_rgb_value \
			init_and_check/get_texture_path \
			init_and_check/ft_reallocTab \
			init_and_check/ft_isGoodFormat \
			init_and_check/normalize_map \
			init_and_check/init_and_free_data \
			init_and_check/ft_checkMap \
			game/cub3D \
			game/generate_textures \
			game/key_management \
			game/handle_mouvement \
			game/close_cross \
			game/create_img \
			game/raycasting \
			game/raycasting2 \

SRC_DIR := src
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
	@echo "$(BOLD)$(RED)🛠️      Compiling cub3D    🛠️$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(MLX) $(UTILS) $(INC_MANDATORY) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀      cub3D fully compiled, ready to use       🚀$(RESET)"
	@echo "\n$(BOLD)Usage: ./cub3D maps/map.cub$(RESET)"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ_FILES)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o cub3D's files   🌀$(RESET)"
	@make clean -sC $(MLX_PATH)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o MiniLibX's files  🌀$(RESET)"

fclean: clean
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned cub3D exec       🌀$(RESET)"

re: fclean all

.PHONY: all clean fclean re

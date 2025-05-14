# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2025/05/14 11:08:19 by jotudela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= cub3D_bonus
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
INC_BONUS		= -I ./inc/\
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
SRC_FILES	= main_bonus \
			utils_bonus \
			init_and_check/ft_init_bonus \
			init_and_check/get_rgb_value_bonus \
			init_and_check/get_texture_path_bonus \
			init_and_check/ft_reallocTab_bonus \
			init_and_check/ft_isGoodFormat_bonus \
			init_and_check/normalize_map_bonus \
			init_and_check/init_and_free_data_bonus \
			init_and_check/ft_checkMap_bonus \
			game/cub3D_bonus \
			game/generate_textures_bonus \
			game/key_management_bonus \
			game/handle_mouvement_bonus \
			game/close_cross_bonus \
			game/create_img_bonus \
			game/raycasting_bonus \
			game/raycasting2_bonus \
			game/draw_minimap_bonus

SRC_DIR := src
SRC_BONUS := $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))

# OBJ
OBJ_FILES	:= $(SRC_BONUS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

###################################################
## RULES

all: $(MLX) $(UTILS) $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INC_BONUS) -c $< -o $@

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
	@echo "$(BOLD)$(RED)🛠️      Compiling cub3D_bonus    🛠️$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(MLX) $(UTILS) $(INC_BONUS) -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀      cub3D_bonus fully compiled, ready to use       🚀$(RESET)"
	@echo "\n$(BOLD)Usage: ./cub3D_bonus maps/map.cub$(RESET)"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ_FILES)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o cub3D_bonus's files   🌀$(RESET)"
	@make clean -sC $(MLX_PATH)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o MiniLibX's files  🌀$(RESET)"

fclean: clean
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned cub3D_bonus exec       🌀$(RESET)"

re: fclean all

.PHONY: all clean fclean re

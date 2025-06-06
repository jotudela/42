# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2025/06/06 10:08:16 by jotudela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror -g
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
			check/is_rectangle \
			game/so_long \
			game/key_management \
			game/key_management2 \
			game/close_game \
			game/generate_map \
			game/position \
			game/is_finish

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

test0:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/map.ber

test00:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/map2.ber

test000:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/map3.ber

test1:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long

test2:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/rectangular.ber

test3:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/format.error

test4:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/nothing.ber

test5:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/wall.ber

test6:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/bad_ie1.ber

test7:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/bad_ie2.ber

test8:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/bad_ie3.ber

test9:
	@valgrind --track-fds=yes --leak-check=full --show-leak-kinds=all ./so_long maps/len.ber

.PHONY: all clean fclean re test0 test1 test2 test3 test4 test5 test6 test7 test8 test9
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2024/11/04 14:46:23 by jojo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror
CC		= gcc

###################################################
### SOURCES

## MANDATORY PART

SRC_FILES	= ft_printf \
			ft_atoi_base \
			ft_strlen \
			list \
			print_from_libft \
			ultinate_parse

OBJ_FILES	= $(addsuffix .o, $(SRC_FILES))

## BONUS PART

SRC_FILES_BONUS	= ft_lstnew_bonus \
		ft_lstadd_front_bonus \
		ft_lstsize_bonus \
		ft_lstlast_bonus \
		ft_lstadd_back_bonus \
		ft_lstdelone_bonus \
		ft_lstclear_bonus \
		ft_lstiter_bonus \
		ft_lstmap_bonus

OBJ_FILES_BONUS	= $(addsuffix .o, $(SRC_FILES_BONUS))

###################################################
## RULES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	ar rcs ${NAME} ${OBJ_FILES}
	ranlib ${NAME}

bonus: all ${OBJ_FILES_BONUS}
	ar rcs ${NAME} ${OBJ_FILES_BONUS}
	ranlib ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
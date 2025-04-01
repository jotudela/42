CC = cc

NAME = libbuiltins.a

EXEC = minishell

CFLAGS = -Wall -Wextra -Werror -Iinclude -DFROM_SUBMODULE # -g -fsanitize=address
ECHO   = src/echo.c
CD     = src/cd.c src/cd_utils2.c src/cd_utils.c
EXIT   = src/exit.c
PWD    = src/pwd.c
UNSET  = src/unset.c
EXPORT = src/export.c src/export_utils2.c src/export_utils.c
ENV    = src/env.c

M_SRC = $(ECHO) $(CD) $(EXIT) $(PWD) $(UNSET) $(EXPORT) $(ENV) src/shell_cmds_utils.c src/shell_cmds_utils2.c src/shell_cmds.c src/ft_lsts.c

EXEC_SRC = main.c $(M_SRC)

M_HEAD = ./shell_cmds.h ./cd.h ./echo.h ./env.h ./export.h ./global_utils.h ./ft_lsts.h ./utils.h

M_OBJ = $(M_SRC:.c=.o)
EXEC_OBJ = main.o $(M_SRC:.c=.o)

LIBFT = ../libft

all: $(NAME) clean

$(NAME): rf_lib $(M_OBJ)
	ar rcs $@ $(M_OBJ)

exec:	$(EXEC_OBJ) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(EXEC_OBJ) $(LIBFT)/libft.a -o $(EXEC)

cp: fclean
	find . -name "*~" -delete

$(LIBFT)/libft.a:
	make -C $(LIBFT) all

%.o : %.c $(M_HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
rf_lib:
	rm -f $(NAME)
clean:
	rm -rf $(M_OBJ)

exec_clean:
	make -C $(LIBFT) clean
	rm -rf $(EXEC_OBJ)

fclean: clean
	rm -rf $(NAME)

exec_fclean: exec_clean
	rm -rf $(EXEC)
	rm -rf $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re bonus

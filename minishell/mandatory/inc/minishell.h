/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:01:53 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/06 16:45:06 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define Hello "\033[31m[\033[34mminishell>\033[31m]\033[0m "
# define PATH_MAX 4096

# include "../../Utils/libft/libft.h"
# include "../../Utils/ft_printf/ft_printf.h"
# include "../../Utils/get_next_line/get_next_line_bonus.h"

# include <stdio.h>          // printf, perror
# include <stdlib.h>         // malloc, free, getenv, exit
# include <unistd.h>         // write, access, read, close, fork, getcwd, chdir, pipe, isatty, ttyslot
# include <readline/readline.h> // readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay
# include <readline/history.h>  // add_history
# include <fcntl.h>          // open
# include <sys/wait.h>       // wait, waitpid, wait3, wait4
# include <signal.h>         // signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/stat.h>       // stat, lstat, fstat
# include <dirent.h>         // opendir, readdir, closedir
# include <string.h>         // strerror
# include <termios.h>        // tcsetattr, tcgetattr
# include <sys/ioctl.h>      // ioctl
# include <curses.h>         // tgetent, tgetflag, tgetnum, tgetstr
# include <term.h>           // tgoto, tputs

typedef struct s_list
{
    char            *path;
    char            **args;
    char            **env;
    char            *file1;
    char            *file2;
    int                     mod;
    struct s_list   *next;
}           t_list;

/* Fonctions de Parsing */

/* Fonctions pour Executer */

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:14:36 by jotudela          #+#    #+#             */
/*   Updated: 2024/12/13 09:42:40 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Utils/libft/libft.h"
# include "../Utils/ft_printf/ft_printf.h"
# include "../Utils/get_next_line/get_next_line_bonus.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <stdint.h>

typedef struct s_list
{
	char			*path;
	char			**args;
	char			**env;
	char			*file1;
	char			*file2;
	int				mod;
	struct s_list	*next;
}			t_args;

void	ft_error(int ac, char **av);
void	ft_lstclear(t_args **lst);
t_args	*ft_lstnew(char *command, char **envp, int mod, char *file);
t_args	*ft_lstlast(t_args *lst);
void	ft_lstadd_back(t_args **lst, t_args *new);
char	*ft_find_cmd(char *cmd);
void	ft_execute_cmd(t_args **li, int in_fd, int out_fd);
void	ft_start(t_args *li);
void	ft_verif(t_args **list, char *str);
t_args	*ft_ultimate_parse(int ac, char **av, char **envp);
void	handle_pipe_error(int pipefd[2]);
void	handle_fork_error(pid_t pid);
void	child_process_handler(int input_fd, int output_fd, t_args *li);
int		open_output_file(char *filename);
void	ft_right_command(t_args *li, int file);

/* --------------------------------------------------------------- */

void	ft_parse(char **av, char **envp);
void	ft_right_commandhd(char **av, int pipefd[2], char **envp, int mod);
void	ft_execute_cmdhd(char *cmd_args, int in_fd, int out_fd, char **envp);
char	*ft_find_cmdhd(char *cmd);
void	here_doc(char **av);
void	ft_stof(char *str);
char	*get_doc(char **av);
void	pre_gnl(void);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_error_here_doc(char **av);

/* --------------------------------------------------------------- */

char	**ft_alloc(char *command, char *file);
void	ft_cleartab(char **tab);
void	msg_error(char *str);
void	ft_close(void);

#endif

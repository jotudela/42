/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:14:36 by jotudela          #+#    #+#             */
/*   Updated: 2024/12/11 13:08:52 by jojo             ###   ########.fr       */
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

void	ft_parse(char **av, char **envp);
char	*ft_find_cmd(char *cmd);
char	**ft_alloc(char *command, char *file);
void	ft_cleartab(char **tab);
void	ft_error(int ac, char **av);
void	ft_error_here_doc(char **av);
void	msg_error(char *str);
void	here_doc(char **av);
int ft_strcmp(const char *s1, const char *s2);

#endif

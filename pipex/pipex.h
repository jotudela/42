/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:14:36 by jotudela          #+#    #+#             */
/*   Updated: 2024/12/05 09:57:30 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

int ft_access_error(char *file1, char *file2);
char **ft_split(const char *s, char c);
char *ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
void    ft_cleartab(char **tab);
void	ft_error(int ac, char **av);
void msg_error(char *str);

#endif

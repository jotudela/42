/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:50:30 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/14 14:23:02 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}           t_list;

/* *************************************************************** */

t_list  *ft_lstnew(char *content);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
char    *ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
void	ft_lstclear(t_list **lst);
char    *get_next_line(int fd);

#endif
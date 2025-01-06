/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:20:09 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/06 14:22:50 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Utils/libft/libft.h"
# include "Utils/ft_printf/ft_printf.h"
# include "Utils/get_next_line/get_next_line_bonus.h"

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

typedef struct	s_list
{
	int			value;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

t_list	*ft_lstnew(int new_value);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	msg_error(char *str);
void	ft_verif(int ac, char **av);

/* ------------------------------------------------------------ */

void    sa(int e1, int e2, t_list **a);
void    sb(int e1, int e2, t_list **b);
void    ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list *b);
void	pb(t_list *a, t_list **b);

#endif

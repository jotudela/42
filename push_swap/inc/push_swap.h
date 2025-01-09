/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:20:09 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/09 14:00:37 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Utils/libft/libft.h"
# include "../Utils/ft_printf/ft_printf.h"
# include "../Utils/get_next_line/get_next_line_bonus.h"

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

typedef struct	s_list
{
	int			value;
	int			index;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

t_list	*ft_lstnew(int new_value);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_init(int ac, char **av);
void	msg_error(char *str);
void	ft_verif(int ac, char **av, int mod);
int		is_ok(t_list *a);

/* ------------------------------------------------------------ */

void radix_sort(t_list **a, t_list **b);
void assign_index(t_list *stack);
void	push(t_list **from, t_list **to);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	reverse_rotate(t_list **stack);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	rotate(t_list **stack);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void    swap(t_list **stack);
void    sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

#endif

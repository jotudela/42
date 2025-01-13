/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:03:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/13 10:14:14 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_list	*get_last_stack(t_list *stack, int mod)
{
	if (mod == 0)
	{
		while (stack && stack->next != NULL)
			stack = stack->next;
		return (stack);
	}
	else
	{
		while (stack && stack->next && stack->next->next != NULL)
			stack = stack->next;
		return (stack);
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*before_tail;

	tail = get_last_stack(*stack, 0);
	before_tail = get_last_stack(*stack, 1);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}

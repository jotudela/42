/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:00:41 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/13 10:15:13 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_last_stack(*stack, 0);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_list **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_list **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:03:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/08 14:53:02 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void reverse_rotate(t_list **stack)
{
    t_list *last;

    if (!(*stack) || !(*stack)->next)
        return;
    last = *stack;
    while (last->next)
        last = last->next;
    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}

void rra(t_list **a)
{
    reverse_rotate(a);
    ft_printf("rra\n");
}

void rrb(t_list **b)
{
    reverse_rotate(b);
    ft_printf("rrb\n");
}

void rrr(t_list **a, t_list **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rrr\n");
}

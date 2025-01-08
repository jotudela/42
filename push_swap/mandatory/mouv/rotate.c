/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:00:41 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/08 14:53:09 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void rotate(t_list **stack)
{
    t_list *first;
    t_list *last;

    if (!(*stack) || !(*stack)->next)
        return;
    first = *stack;
    last = *stack;
    while (last->next)
        last = last->next;
    *stack = first->next;
    (*stack)->prev = NULL;
    first->next = NULL;
    first->prev = last;
    last->next = first;
}

void ra(t_list **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void rb(t_list **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void rr(t_list **a, t_list **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}
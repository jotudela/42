/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:58:10 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/08 14:52:55 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void push(t_list **from, t_list **to)
{
    t_list *node;

    if (!(*from))
        return;
    node = *from;
    *from = node->next;
    if (*from)
        (*from)->prev = NULL;
    node->next = *to;
    if (*to)
        (*to)->prev = node;
    *to = node;
    node->prev = NULL;
}

void pa(t_list **a, t_list **b)
{
    push(b, a);
    ft_printf("pa\n");
}

void pb(t_list **a, t_list **b)
{
    push(a, b);
    ft_printf("pb\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:52:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/08 14:53:15 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    swap(t_list **stack)
{
    t_list *first;
    t_list *second;

    if (!(*stack) || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    *stack = second;
}

void    sa(t_list **a)
{
    swap(a);
    ft_printf("sa\n");
}

void sb(t_list **b)
{
    swap(b);
    ft_printf("sb\n");
}

void ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:52:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/13 10:16:08 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_list *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	sa(t_list **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	sb(t_list **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}

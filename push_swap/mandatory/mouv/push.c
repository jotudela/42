/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:58:10 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/13 10:11:31 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (*from == NULL)
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = tmp;
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
	ft_printf("pb\n");
}

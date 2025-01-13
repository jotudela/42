/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:07:00 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/13 09:58:49 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	push_all_save_three(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

static void	shift_stack(t_list **stack_a)
{
	int	lowest_pos;
	int	size;

	size = stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > size / 2)
	{
		while (lowest_pos < size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}

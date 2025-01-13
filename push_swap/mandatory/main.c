/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:13:07 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/13 11:31:18 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_size(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	assign_index(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		size;

	b = NULL;
	a = ft_init(ac, av);
	size = stack_size(a);
	assign_index(a, size + 1);
	push_swap(&a, &b, size);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}

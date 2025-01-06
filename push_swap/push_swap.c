/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:20:01 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/06 14:52:45 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_veriflst(t_list **li)
{
	if (!(*li) || !(*li)->value)
	{
		ft_lstclear(li);
		msg_error("Error\n");
	}
}

t_list	*ft_initlist(int ac, char **av, int mod)
{
	t_list	*li;
	int		i;

	if (mod == 1)
	{
		li = ft_lstnew(ft_atoi(av[1]));
		i = 2;
	}
	else
	{
		li = ft_lstnew(ft_atoi(av[0]));
		i = 1;
	}
	ft_veriflst(&li);
	while (i < ac)
	{
		ft_lstadd_back(&li, ft_lstnew(ft_atoi(av[i])));
		ft_veriflst(&li);
		i++;
	}
	return (li);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	char	**tab;

	if (ac < 2)
		exit(EXIT_FAILURE);
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		a = ft_initlist(ac, tab, 2);
	}
	a = ft_initlist(ac, av, 1);
	while (a)
	{
		ft_printf("%i\n", a->value);
		a = a->next;
	}
	free(tab);
	ft_lstclear(&a);
}

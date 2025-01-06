/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:20:01 by jotudela          #+#    #+#             */
/*   Updated: 2024/12/17 16:01:09 by jojo             ###   ########.fr       */
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

t_list	*ft_initlist(int ac, char **av)
{
	t_list	*li;
	int		i;

	li = ft_lstnew(ft_atoi(av[1]));
	ft_veriflst(&li);
	i = 2;
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
	t_list	*li;
	if (ac < 2)
		exit(EXIT_FAILURE);
	ft_verif(ac, av);
	li = ft_initlist(ac, av);
	while (li)
	{
		ft_printf("%i\n", li->value);
		li = li->next;
	}
	ft_lstclear(&li);
}

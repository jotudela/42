/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_parse_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:21:40 by jojo              #+#    #+#             */
/*   Updated: 2024/12/12 11:22:56 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_verif(t_args **list, char *str)
{
	if ((*list) == NULL || (*list)->path == NULL || (*list)->args == NULL)
	{
		ft_lstclear(list);
		msg_error(str);
	}
}

t_args	*ft_ultimate_parse(int ac, char **av, char **envp)
{
	int		i;
	t_args	*li;

	i = 3;
	li = ft_lstnew(av[2], envp, 1, av[1]);
	ft_verif(&li, "erreur boucle");
	while (i < ac - 2)
	{
		ft_lstadd_back(&li, ft_lstnew(av[i], envp, 0, NULL));
		ft_verif(&li, "erreur boucle");
		i++;
	}
	ft_lstadd_back(&li, ft_lstnew(av[ac - 2], envp, 2, av[ac - 1]));
	ft_verif(&li, "erreur boucle");
	return (li);
}

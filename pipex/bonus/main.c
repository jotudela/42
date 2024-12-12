/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:35:47 by jojo              #+#    #+#             */
/*   Updated: 2024/12/12 13:41:55 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_args	*li;

	if (ac == 1)
		msg_error("Format incorrect");
	else if (ft_strcmp(av[1], "here_doc") == 0 && ac == 6)
	{
		ft_error_here_doc(av);
		here_doc(av);
		ft_parse(av, envp);
		unlink("here_doc");
	}
	else if (ft_strcmp(av[1], "here_doc") != 0 && ac >= 5)
	{
		ft_error(ac, av);
		li = ft_ultimate_parse(ac, av, envp);
		ft_start(li);
		ft_lstclear(&li);
	}
	else
		msg_error("Format incorrect");
	return (0);
}

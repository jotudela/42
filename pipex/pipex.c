/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:10:48 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/26 20:13:55 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	if (ft_error(ac, av) == 1)
		exit(EXIT_FAILURE);
	return (0);
}


int	ft_error(int ac, char **av)
{
	pid_t	pid;
	char	*args[] = {"touch", av[4], NULL};
	char	*env[] = {NULL};

	if (ac != 5)
		return (ft_printf("Nombre d'arguments incorecte.\n"), 1);
	else if (access(av[1], F_OK) == -1)
		return (ft_printf("Le fichier %s existe pas.\n", av[1]), 1);
	else if (access(av[4], F_OK) == -1)
	{
		pid = fork();
		if (pid == -1)
			return (ft_printf("Erreur fork.\n"), 1);
		if (pid == 0)
			if (execve("/usr/bin/touch", args, env) == -1)
				return (ft_printf("Erreur execve\n"), 1);
	}
	return (0);
}

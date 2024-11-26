/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:10:48 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/26 14:52:35 by jotudela         ###   ########.fr       */
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
	int	status;

	if (ac != 5)
		return (ft_putstr_fd("Nombre d'arguments incorecte.\n", 2), 1);
	else if (access(av[1], F_OK) == -1)
		return (ft_putstr_fd("Le premier fichier existe pas.\n", 2), 1);
	else if (access(av[4], F_OK) == -1)
	{
		pid = fork();
		if (pid == -1)
			return (ft_putstr_fd("Erreur fork.\n", 2), 1);
		if (pid == 0)
		{
			if (execve("/usr/bin/touch", args, env) == -1)
				return (ft_putstr_fd("Erreur execve", 2), 1);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
				ft_putstr_fd("GOOD", 1);
			else
				ft_putstr_fd("NO GOOD", 2);
		}
	}
	return (0);
}

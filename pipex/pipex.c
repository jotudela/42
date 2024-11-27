/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:10:48 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/26 23:16:44 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	if (ft_error(ac, av) == 1)
		exit(EXIT_FAILURE);
	if (ft_parsing(ac, av, fd) == 1)
		exit(EXIT_FAILURE);
	return (0);
}

int	ft_parsing(int ac, char **av, int fd)
{
	int	i;
	int	pipefd[2];
	pid_t	pid;
	char	*buffer;

	if (pipe(pipefd) == -1)
		return (ft_printf("Erreur pipe.\n"), 1);
	dup2(fd, pipefd);
	i = 1;
	while (i < ac - 1)
	{
		buffer = malloc(sizeof(char) * ft_strlen(av[i]));
		pid = fork();
		if (pid == 0)
		{
			close(pipefd[1]);
			read(pipefd[0], buffer, ft_strlen(buffer));
			close(pipefd[1]);
		}
		else if (pid > 0)
		{
			
		}
	}
}

int	ft_error(int ac, char **av)
{
	pid_t	pid;
	char	*args[] = {"touch", av[4], NULL};

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
			if (execve("/usr/bin/touch", args, NULL) == -1)
				return (ft_printf("Erreur execve\n"), 1);
	}
	return (0);
}

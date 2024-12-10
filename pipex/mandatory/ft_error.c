/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:35:52 by jojo              #+#    #+#             */
/*   Updated: 2024/12/10 16:55:50 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_cleartab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**ft_alloc(char *command, char *file)
{
	char	*tmp;
	char	**str;

	tmp = ft_strjoin(command, file);
	if (!tmp)
		return (NULL);
	str = ft_split(tmp, ' ');
	if (!str)
		return (NULL);
	free(tmp);
	return (str);
}

void	ft_error(int ac, char **av)
{
	pid_t	pid;
	char	**args;

	if (ac != 5)
		msg_error("Number of argument not correct.");
	else if (access(av[1], F_OK) == -1)
		msg_error("File 1");
	args = ft_alloc("touch ", av[4]);
	if (args == NULL)
	{
		ft_cleartab(args);
		msg_error("Can't malloc args.");
	}
	else if (access(av[4], F_OK) == -1)
	{
		pid = fork();
		if (pid == -1)
		{
			ft_cleartab(args);
			msg_error("Erreur fork.");
		}
		if (pid == 0)
			execve("/usr/bin/touch", args, NULL);
	}
	ft_cleartab(args);
}

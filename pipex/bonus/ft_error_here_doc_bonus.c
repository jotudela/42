/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_here_doc_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:35:52 by jojo              #+#    #+#             */
/*   Updated: 2024/12/12 13:52:49 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	**ft_alloc(char *command, char *file)
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

void	ft_error_here_doc(char **av)
{
	pid_t	pid;
	char	**args;

	args = ft_alloc("touch ", av[5]);
	if (args == NULL)
	{
		ft_cleartab(args);
		msg_error("Can't malloc args.");
	}
	else if (access(av[5], F_OK) == -1)
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

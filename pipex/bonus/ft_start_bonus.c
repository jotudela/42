/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:38:47 by jojo              #+#    #+#             */
/*   Updated: 2024/12/13 09:47:41 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_find_cmd(char *cmd)
{
	char	**dirs;
	char	*full_path;
	char	*temp;
	int		i;

	dirs = ft_split("/bin /usr/bin /usr/local/bin /opt/homebrew/bin"
			" /opt/homebrew/sbin /usr/sbin /sbin", ' ');
	i = 0;
	while (dirs[i])
	{
		temp = ft_strjoin(dirs[i], "/");
		if (!temp)
			return (free(temp), ft_cleartab(dirs), NULL);
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (!full_path)
			return (free(full_path), ft_cleartab(dirs), NULL);
		if (access(full_path, X_OK) == 0)
			return (ft_cleartab(dirs), full_path);
		free(full_path);
		i++;
	}
	return (ft_cleartab(dirs), NULL);
}

void	ft_execute_cmd(t_args **li, int in_fd, int out_fd)
{
	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(in_fd);
	close(out_fd);
	ft_close();
	if (execve((*li)->path, (*li)->args, (*li)->env) == -1)
	{
		ft_lstclear(li);
		msg_error("Erreur execution commande.");
	}
}

void	ft_start(t_args *li)
{
	int		pipefd[2];
	int		file;
	pid_t	pid;

	if (pipe(pipefd) == -1)
		msg_error("pipe");
	pid = fork();
	if (pid == -1)
		msg_error("Pid");
	if (pid == 0)
	{
		file = open(li->file1, O_RDONLY);
		if (file == -1)
			msg_error("Impossible d'ouvrir le fichier d'entrée.");
		ft_right_command(li, file);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	ft_close();
	waitpid(pid, NULL, 0);
}

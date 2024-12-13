/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:10:48 by jotudela          #+#    #+#             */
/*   Updated: 2024/12/13 15:39:24 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_find_cmdhd(char *cmd)
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

void	ft_execute_cmdhd(char *cmd_args, int in_fd, int out_fd, char **envp)
{
	char	*path_cmd;
	char	**cmd;

	dup2(in_fd, STDIN_FILENO);
	dup2(out_fd, STDOUT_FILENO);
	close(in_fd);
	close(out_fd);
	unlink("here_doc");
	cmd = ft_split(cmd_args, ' ');
	if (!cmd)
		msg_error("Erreur allocation commande.");
	path_cmd = ft_find_cmdhd(cmd[0]);
	if (!path_cmd)
	{
		ft_cleartab(cmd);
		msg_error("Commande introuvable.");
	}
	if (execve(path_cmd, cmd, envp) == -1)
		msg_error("Erreur execution commande.");
	free(path_cmd);
	ft_cleartab(cmd);
}

void	ft_right_commandhd(char **av, int pipefd[2], char **envp, int mod)
{
	int	file;

	if (mod == 1)
	{
		close(pipefd[0]);
		file = open("here_doc", O_RDONLY);
		if (file == -1)
			msg_error("Can't open here_doc");
		ft_execute_cmdhd(av[3], file, pipefd[1], envp);
	}
	else if (mod == 2)
	{
		close(pipefd[1]);
		file = open(av[5], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (file == -1)
			msg_error("Can't open file.");
		ft_execute_cmdhd(av[4], pipefd[0], file, envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
}

void	ft_parse(char **av, char **envp)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(pipefd) == -1)
		msg_error("pipe");
	pid1 = fork();
	if (pid1 == -1)
		msg_error("Pid1");
	if (pid1 == 0)
		ft_right_commandhd(av, pipefd, envp, 1);
	pid2 = fork();
	if (pid2 == -1)
		msg_error("Pid2");
	if (pid2 == 0)
		ft_right_commandhd(av, pipefd, envp, 2);
	close(pipefd[0]);
	close(pipefd[1]);
	ft_close();
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

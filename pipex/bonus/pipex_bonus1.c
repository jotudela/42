/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:10:48 by jotudela          #+#    #+#             */
/*   Updated: 2024/12/13 09:53:06 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	handle_pipe_error(int pipefd[2])
{
	if (pipe(pipefd) == -1)
		msg_error("Erreur pipe.");
}

void	handle_fork_error(pid_t pid)
{
	if (pid == -1)
		msg_error("Erreur fork.");
}

void	child_process_handler(int input_fd, int output_fd, t_args *li)
{
	int	pipefd[2];

	pipe(pipefd);
	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	ft_execute_cmd(&li, input_fd, output_fd);
	exit(EXIT_FAILURE);
}

int	open_output_file(char *filename)
{
	int	file;

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		msg_error("Erreur ouverture fichier de sortie.");
	return (file);
}

void	ft_right_command(t_args *li, int file)
{
	int		pipefd[2];
	pid_t	pid;

	while (li && li->file2 == NULL)
	{
		handle_pipe_error(pipefd);
		pid = fork();
		handle_fork_error(pid);
		if (pid == 0)
			child_process_handler(file, pipefd[1], li);
		close(pipefd[1]);
		close(file);
		file = pipefd[0];
		li = li->next;
		waitpid(-1, NULL, 0);
	}
	file = open_output_file(li->file2);
	pid = fork();
	handle_fork_error(pid);
	if (pid == 0)
		child_process_handler(pipefd[0], file, li);
	close(pipefd[0]);
	close(file);
	ft_close();
	waitpid(-1, NULL, 0);
}

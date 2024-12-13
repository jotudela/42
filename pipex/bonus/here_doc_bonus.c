/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:40:14 by jojo              #+#    #+#             */
/*   Updated: 2024/12/13 15:46:40 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	pre_gnl(void)
{
	write(STDOUT_FILENO, "\033[31m", ft_strlen("\033[31m"));
	write(1, "──(", 7);
	write(STDOUT_FILENO, "\033[34m", ft_strlen("\033[34m"));
	write(1, "pipex here_doc", 14);
	write(STDOUT_FILENO, "\033[31m", ft_strlen("\033[31m"));
	write(1, ")── ", 8);
	write(STDOUT_FILENO, "\033[0m", ft_strlen("\033[0m"));
}

char	*get_doc(char **av)
{
	char	*str;
	char	*tmp;
	char	*limiter;
	char	*new_tmp;

	pre_gnl();
	str = get_next_line(1);
	if (!str)
		return (NULL);
	tmp = ft_strdup("");
	limiter = ft_strjoin(av[2], "\n");
	while (ft_strcmp(str, limiter) != 0)
	{
		new_tmp = ft_strjoin(tmp, str);
		free(tmp);
		tmp = new_tmp;
		free(str);
		pre_gnl();
		str = get_next_line(1);
		if (!str)
			break ;
	}
	free(str);
	free(limiter);
	return (tmp);
}

void	ft_stof(char *str)
{
	int	fd;

	fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		free(str);
		msg_error("Error: can't open here_doc.");
	}
	if (write(fd, str, ft_strlen(str)) == -1)
	{
		close(fd);
		free(str);
		msg_error("Error: write failed.");
	}
	close(fd);
}

void	here_doc(char **av)
{
	char	*str;

	str = get_doc(av);
	if (str == NULL)
		msg_error("Error in get_doc");
	ft_stof(str);
	free(str);
}

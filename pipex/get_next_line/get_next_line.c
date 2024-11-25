/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:46:33 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/19 15:57:28 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t			i;
	unsigned char	*str1;

	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen(s));
	str1 = (unsigned char *)s;
	while (str1[i])
	{
		if (str1[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		newline_pos;

	if (!stash)
		return (NULL);
	newline_pos = 0;
	while (stash[newline_pos] && stash[newline_pos] != '\n')
		newline_pos++;
	if (stash[newline_pos] == '\n')
		newline_pos++;
	line = ft_substr(stash, 0, newline_pos);
	return (line);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	while (!ft_strchr(stash, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buffer);
			if (read_bytes < 0 || !*stash)
				return (free(stash), NULL);
			return (stash);
		}
		buffer[read_bytes] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
	}
	return (free(buffer), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return (line);
}

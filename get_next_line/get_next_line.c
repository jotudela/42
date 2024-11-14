/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:49:42 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/14 14:51:02 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
    size_t	i;

	if (count == 0 || size == 0)
		return (malloc(0));
	else if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*get_line(t_list *lst)
{
	char	*line;

	line = ft_strdup(lst->content);
	return (line);
}

char    *get_next_line(int fd)
{
    t_list	*li = NULL;
	t_list	*new = NULL;
	char	buf[BUFFER_SIZE + 2];
	static int	i = 0;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (i == 0)
	{
		i = 1;
		while (read(fd, buf, BUFFER_SIZE + 2) > 0)
		{
			new = ft_lstnew(buf);
			if (!new)
				return (NULL);
			ft_lstadd_back(&li, new);
		}
	}
	return (get_line(li));
}

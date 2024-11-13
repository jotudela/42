/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:41:09 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/13 16:16:22 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_line_from_buf(char *buf, int *pos, ssize_t *size)
{
    char    *line;
    int     i;

    i = 0;
    while ((*pos + i) < *size)
    {
        if (buf[*pos + i] == '\n')
            break;
        i++;
    }
    line = calloc(i + 2, sizeof(char));
    if (!line)
        return (NULL);
    ft_strlcpy(line, &buf[*pos], i + 2);
    *pos += i + 1;
    return (line);
}

char *get_next_line(int fd)
{
    static char     buf[BUFFER_SIZE];
    static int      pos = 0;
    static ssize_t  size = 0;
    char           *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (pos >= size)
    {
        size = read(fd, buf, BUFFER_SIZE);
        pos = 0;
        if (size <= 0)
            return (NULL);
    }
    line = get_line_from_buf(buf, &pos, &size);
    return (line);
}

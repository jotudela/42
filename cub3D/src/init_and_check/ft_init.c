/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:19:46 by jojo              #+#    #+#             */
/*   Updated: 2025/04/28 22:10:10 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static char **ft_reallocTab(t_data **data, char *line)
{
    
}

static int    ft_take_data2(t_data **data, int fd)
{
    char    *line;

    line = get_next_line(fd);
    while (line != NULL)
    {
        if (line[0] == '\n' && ft_strlen(line) == 1)
        {
            free(line);
            line = get_next_line(fd);
            continue;
        }

    }
}

static int ft_take_data(t_data **data, int fd)
{
    char *line;

    line = get_next_line(fd);
    while (line != NULL)
    {
        if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
            || ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
            ft_get_texture_path(data, line);
        else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
            ft_get_rgb(data, line);
        if ((*data)->img.path_NO && (*data)->img.path_SO
            && (*data)->img.path_WE && (*data)->img.path_EA
            && (*data)->img.F && (*data)->img.C)
                return (free(line), 0);
        free(line);
        line = get_next_line(fd);
    }
    return (-1);
}

int    ft_init_data(t_data **data, char *file)
{
    int fd;
    
    fd = open(file, O_RDONLY);
    if (!fd)
        (free_data(data), error("error: file: can't open file !\n"), exit(1));
    
    if (ft_take_data(data, fd) == -1)
        (free_data(data), error("error: parsing: fatal\n"), close(fd), exit(1));
     if (ft_take_data2(data, fd) == -1)
        (free_data(data), error("error: parsing: fatal\n"), close(fd), exit(1));
    close(fd);
    printf("path_NO: %s", (*data)->img.path_NO ? (*data)->img.path_NO : "NULL");
    printf("path_SO: %s", (*data)->img.path_SO ? (*data)->img.path_SO : "NULL");
    printf("path_WE: %s", (*data)->img.path_WE ? (*data)->img.path_WE : "NULL");
    printf("path_EA: %s", (*data)->img.path_EA ? (*data)->img.path_EA : "NULL");
    printf("C: %d\n", (*data)->img.C);
    printf("F: %d", (*data)->img.F);
    return (0);
}

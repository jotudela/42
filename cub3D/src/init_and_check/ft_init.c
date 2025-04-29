/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:19:46 by jojo              #+#    #+#             */
/*   Updated: 2025/04/29 18:39:15 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

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
        if (ft_reallocTab(data, line) == -1)
            return (free(line), -1);
        free(line);
        line = get_next_line(fd);
    }
    if (!(*data)->map->tab)
        return (-1);
    return (0);
}

static int ft_take_data(t_data **data, int fd)
{
    char    *line;
    int     i;

    line = get_next_line(fd);
    while (line != NULL)
    {
        i = 0;
        while (line[i])
        {
            if (ft_strncmp(line + i, "NO", 2) == 0 || ft_strncmp(line + i, "SO", 2) == 0
                || ft_strncmp(line + i, "WE", 2) == 0 || ft_strncmp(line + i, "EA", 2) == 0)
                ft_get_texture_path(data, line + i);
            else if (ft_strncmp(line + i, "F", 1) == 0 || ft_strncmp(line + i, "C", 1) == 0)
                ft_get_rgb(data, line + i);
            i++;
        }
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
        (free_data(data), error("error: parsing: take data 1 fail\n"), close(fd), exit(1));
    if (ft_take_data2(data, fd) == -1)
        (free_data(data), error("error: parsing: take data 2 fail\n"), close(fd), exit(1));
    close(fd);
    if (ft_coppyTab(data) == -1)
        (free_data(data), error("\tError\n\tparsing: fatal\n"), exit(1));
    fd = ft_checkPlayer(data);
    if (fd == -1)
        (free_data(data), error("error: parsing: too many player in map\n"), exit(1));
    else if (fd == -2)
        (free_data(data), error("error: parsing: no player in map\n"), exit(1));
    if (ft_checkChar(data) == -1)
        (free_data(data), error("error: parsing: one or more char is invalid\n"), exit(1));
    if (flood_fill(data, (*data)->map->map_x, (*data)->map->map_y) == -1)
        (free_data(data), error("error: parsing: map is invalid\n"), exit(1));
    return (0);
}

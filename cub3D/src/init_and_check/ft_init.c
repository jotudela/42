/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:19:46 by jojo              #+#    #+#             */
/*   Updated: 2025/04/28 10:54:25 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void    ft_take_data2(t_data **data, int fd)
{

}

void    ft_take_data(t_data **data, int fd)
{
    char    *line;

    line = get_next_line(fd);
    if (!line)
        (error("error: file: can't read file !\n"), exit(1));
    while (line != EOF)
    {
        if (ft_strncmp(line, "NO", 3) == 0
            || ft_strncmp(line, "SO", 3) == 0
            || ft_strncmp(line, "WE", 3) == 0
            || ft_strncmp(line, "EA", 3) == 0)
            ft_get_texture_path(data, line);
        if (ft_strncmp(line, "F", 2) == 0
            || ft_strncmp(line, "C", 2) == 0)
            ft_get_rbg(data, line);
        free(line);
        line = get_next_line(fd);
        if ((*data)->img.path_NO && (*data)->img.path_SO
            && (*data)->img.path_WE && (*data)->img.path_EA)
            break ;
    }
    if (!(*data)->img.path_NO || !(*data)->img.path_SO
        || !(*data)->img.path_WE || !(*data)->img.path_EA)
}

void    ft_init_data(t_data **data, char *file)
{
    int fd;
    
    fd = open(file, O_RDONLY);
    if (!fd)
        (error("error: file: can't open file !\n"), exit(1));
    ft_take_data(data, fd);
}
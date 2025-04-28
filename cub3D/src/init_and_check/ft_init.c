/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:19:46 by jojo              #+#    #+#             */
/*   Updated: 2025/04/28 17:54:06 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

/*static int    ft_take_data2(t_data **data, int fd, int raw)
{

}*/

static int ft_take_data(t_data **data, int fd)
{
    char *line;
    int raw;

    raw = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
            || ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
            ft_get_texture_path(data, line);
        else if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
            ft_get_rgb(data, line);
        raw++;
        if ((*data)->img.path_NO && (*data)->img.path_SO
            && (*data)->img.path_WE && (*data)->img.path_EA
            && (*data)->img.F && (*data)->img.C)
            return (free(line), raw);
        free(line);
        line = get_next_line(fd);
    }
    return (free(line), -1);
}

int    ft_init_data(t_data **data, char *file)
{
    int fd;
    int raw;
    
    fd = open(file, O_RDONLY);
    if (!fd)
        (free_data(data), error("error: file: can't open file !\n"), exit(1));
    raw = ft_take_data(data, fd);
    if (raw == -1)
        (free_data(data), error("error: parsing: fatal\n"), close(fd), exit(1));
    //ft_take_data2(data, fd, raw);
    close(fd);
    return (0);
}

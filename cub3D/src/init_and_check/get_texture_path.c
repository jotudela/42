/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:01:54 by jotudela          #+#    #+#             */
/*   Updated: 2025/04/28 16:29:58 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void  ft_get_texture_path(t_data **data, char *line)
{
    int i;
    int dir;

    i = 0;
    if (ft_strncmp(line, "NO", 2) == 0)
        dir = 0;
    else if (ft_strncmp(line, "SO", 2) == 0)
        dir = 1;
    else if (ft_strncmp(line, "WE", 2) == 0)
        dir = 2;
    else if (ft_strncmp(line, "EA", 2) == 0)
        dir = 3;
    while (line[i] != ' ' && line[i] != '\t')
        i++;
    if (dir == 0)
        (*data)->img.path_NO = ft_strtrim(line + i, " \t");
    else if (dir == 1)
        (*data)->img.path_SO = ft_strtrim(line + i, " \t");
    else if (dir == 2)
        (*data)->img.path_WE = ft_strtrim(line + i, " \t");
    else if (dir == 3)
        (*data)->img.path_EA = ft_strtrim(line + i, " \t");
}

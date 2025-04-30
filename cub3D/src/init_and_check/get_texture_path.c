/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:01:54 by jotudela          #+#    #+#             */
/*   Updated: 2025/04/30 18:00:34 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void ft_verif_is_allocated(t_data ** data, int dir)
{
    if ((*data)->img.path_NO && dir == 0)
        free((*data)->img.path_NO);
    else if ((*data)->img.path_SO && dir == 1)
        free((*data)->img.path_SO);
    else if ((*data)->img.path_WE && dir == 2)
        free((*data)->img.path_WE);
    else if ((*data)->img.path_EA && dir == 3)
        free((*data)->img.path_EA);
}

static char *add_quotes(char *line)
{
    
}

void  ft_get_texture_path(t_data **data, char *line)
{
    int dir;

    dir = -1;
    if (ft_strncmp(line, "NO", 2) == 0)
        dir = 0;
    else if (ft_strncmp(line, "SO", 2) == 0)
        dir = 1;
    else if (ft_strncmp(line, "WE", 2) == 0)
        dir = 2;
    else if (ft_strncmp(line, "EA", 2) == 0)
        dir = 3;
    ft_verif_is_allocated(data, dir);
    if (dir == 0)
        (*data)->img.path_NO = ft_strtrim(line + 2, " \t");
    else if (dir == 1)
        (*data)->img.path_SO = ft_strtrim(line + 2, " \t");
    else if (dir == 2)
        (*data)->img.path_WE = ft_strtrim(line + 2, " \t");
    else if (dir == 3)
        (*data)->img.path_EA = ft_strtrim(line + 2, " \t");
}

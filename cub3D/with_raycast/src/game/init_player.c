/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:55:02 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/01 14:03:41 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    init_player(t_data **data)
{
    int x;
    int y;

    x = (*data)->map->map_x;
    y = (*data)->map->map_y;
    (*data)->player.pos.x = x + 0.5;
    (*data)->player.pos.y = y + 0.5;
    if ((*data)->map->tab[y][x] == 'N')
    {
        (*data)->player.dir.x = 0.0;
        (*data)->player.dir.y = -1.0;
        (*data)->player.plane.x = 0.66;
        (*data)->player.plane.y = 0.0;
    }
    else if ((*data)->map->tab[y][x] == 'S')
    {
        (*data)->player.dir.x = 0.0;
        (*data)->player.dir.y = 1.0;
        (*data)->player.plane.x = -0.66;
        (*data)->player.plane.y = 0.0;
    }
    else if ((*data)->map->tab[y][x] == 'E')
    {
        (*data)->player.dir.x = 1.0;
        (*data)->player.dir.y = 0.0;
        (*data)->player.plane.x = 0.0;
        (*data)->player.plane.y = 0.66;
    }
    else if ((*data)->map->tab[y][x] == 'W')
    {
        (*data)->player.dir.x = -1.0;
        (*data)->player.dir.y = 0.0;
        (*data)->player.plane.x = 0.0;
        (*data)->player.plane.y = -0.66;
    }
    (*data)->map->tab[y][x] = '0';
    return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:35:10 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/20 14:23:18 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    position(t_data *data, t_map *map)
{
    int x;
    int y;

    y = 0;
    while (map)
    {
        x = 0;
        while (map->line[x])
        {
            if (map->line[x] == 'P')
            {
                data->player.x = x;
                data->player.y = y;
                return ;
            }
            x++;
        }
        y++;
        map = map->next;
    }
}
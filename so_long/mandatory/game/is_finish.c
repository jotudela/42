/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:33:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 10:46:46 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    is_finish(t_data *data, t_map *map)
{
    int i;

    i = 0;
    while (i++ < data->player.ye && map)
        map = map->next;
    if (data->player.ni == (*(data->su))->item && map->line[data->player.xe] == '2')
    {
        ft_printf("You win the game !\n");
        close_win(data);
    }
}

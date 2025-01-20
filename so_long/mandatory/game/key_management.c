/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:27:31 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/20 18:16:41 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void gauche(t_data *data, t_map *map)
{
    int i;
    
    i = 0;
    while (i++ < data->player.y && map)
        map = map->next;
    if (map->line[data->player.x - 1] == '1')
        return ;
    print_image(data, data->img.floor, data->player.x, data->player.y);
    map->line[data->player.x] = '0';
    data->player.x -= 1;
    map->line[data->player.x] = 'P';
    print_image(data, data->img.link, data->player.x, data->player.y);
    data->actions++;
}

static void droite(t_data *data, t_map *map)
{
    int i;
    
    i = 0;
    while (i++ < data->player.y && map)
        map = map->next;
    if (map->line[data->player.x + 1] == '1')
        return ;
    print_image(data, data->img.floor, data->player.x, data->player.y);
    map->line[data->player.x] = '0';
    data->player.x += 1;
    map->line[data->player.x] = 'P';
    print_image(data, data->img.link, data->player.x, data->player.y);
    data->actions++;
}

static void bas(t_data *data, t_map *map)
{
    int i;
    
    i = 0;
    while (i++ < data->player.y && map)
        map = map->next;
    if (map->next->line[data->player.x] == '1')
        return ;
    print_image(data, data->img.floor, data->player.x, data->player.y);
    map->line[data->player.x] = '0';
    data->player.y += 1;
    map->next->line[data->player.x] = 'P';
    print_image(data, data->img.link, data->player.x, data->player.y);
    data->actions++;
}

static void haut(t_data *data, t_map *map)
{
    int     i;
    
    i = 0;
    while (i++ < data->player.y && map)
        map = map->next;
    if (map->prev->line[data->player.x] == '1')
        return ;
    print_image(data, data->img.floor, data->player.x, data->player.y);
    map->line[data->player.x] = '0';
    data->player.y -= 1;
    map->prev->line[data->player.x] = 'P';
    print_image(data, data->img.link, data->player.x, data->player.y);
    data->actions++;
}

int Key_press(int keycode, t_data *data)
{
    position(data, *data->map);
    if (keycode == XK_Escape)
    {
        ft_printf("ESCAPE\n");
        close_win(data);
    }
    if (keycode == 97)//gauche
        gauche(data, *data->map);
    if (keycode == 100)//droite
        droite(data, *data->map);
    if (keycode == 115)//bas
        bas(data, *data->map);
    if (keycode == 119)//haut
        haut(data, *data->map);
    ft_printf("Numbers of actions : %i\n", data->actions);
    return (0);
}

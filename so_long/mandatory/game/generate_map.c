/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:02:59 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/16 17:51:53 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    print_image(t_data *data, void *img, int x, int y)
{
    mlx_put_image_to_window(data->mlx, data->win, img, x * data->img.x, y * data->img.y);
}

int generate_textures(t_data *data)
{
    data->img.x = 32;
    data->img.y = 32;
    data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->img.x, &data->img.y);
    data->img.tree = mlx_xpm_file_to_image(data->mlx, TREE, &data->img.x, &data->img.y);
    data->img.floor = mlx_xpm_file_to_image(data->mlx, FLOOR, &data->img.x, &data->img.y);
    data->img.link = mlx_xpm_file_to_image(data->mlx, LINK, &data->img.x, &data->img.y);
    data->img.triforce = mlx_xpm_file_to_image(data->mlx, TRIFORCE, &data->img.x, &data->img.y);
    //data->img.exit1 = mlx_xpm_file_to_file(data->mlx, EXIT1, &data->img.x, &data->img.y);
    //data->img.exit2 = mlx_xpm_file_to_file(data->mlx, EXIT2, &data->img.x, &data->img.y);
    if (!data->img.wall || !data->img.tree || !data->img.floor || !data->img.link || !data->img.triforce/* || !data->img.exit1 || !data->img.exit2*/)
        return (1);
    return (0);
}

void    print_map(t_data *data, t_map *map)
{
    int x;
    int y;

    y = 0;
    while (map)
    {
        x = 0;
        while (x < map->len_line && map->line[x])
        {
            print_image(data, data->img.floor, x, y);
            if (map->line[x] == '1')
            {
                if ((x > 0 && x < map->len_line - 1) && (y > 0 && y < ft_lstlen(map)))
                    print_image(data, data->img.tree, x, y);
                else
                    print_image(data, data->img.wall, x, y);
            }
            else if (map->line[x] == 'P')
                print_image(data, data->img.link, x, y);
            else if (map->line[x] == 'C')
                print_image(data, data->img.triforce, x, y);
            x++;
        }
        y++;
        map = map->next;
    }
}

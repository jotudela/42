/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:52:04 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/05 18:10:30 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_data  *init_data(void)
{
    t_data  *data;

    data = ft_calloc(sizeof(*data), 1);
    if (!data)
        (error("error: allocation fail\n"), exit(1));
    data->mlx = NULL;
    data->win = NULL;
    data->map = ft_calloc(sizeof(t_map), 1);
    if (!data->map)
        (error("error: allocation fail\n"), free(data), exit(1));
    data->keys.a = 0;
    data->keys.d = 0;
    data->keys.w = 0;
    data->keys.s = 0;
    data->keys.left = 0;
    data->keys.right = 0;
    return (data);
}

void    free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

static void free_data2(t_data **data)
{
    if ((*data)->minimap.m_img_ptr)
        mlx_destroy_image((*data)->mlx, (*data)->minimap.m_img_ptr);
    if ((*data)->img.NO)
        mlx_destroy_image((*data)->mlx, (*data)->img.NO);
    if ((*data)->img.SO)
        mlx_destroy_image((*data)->mlx, (*data)->img.SO);
    if ((*data)->img.WE)
        mlx_destroy_image((*data)->mlx, (*data)->img.WE);
    if ((*data)->img.EA)
        mlx_destroy_image((*data)->mlx, (*data)->img.EA);
    if ((*data)->img.b_img_ptr)
        mlx_destroy_image((*data)->mlx, (*data)->img.b_img_ptr);
    if ((*data)->mlx && (*data)->win)
        mlx_destroy_window((*data)->mlx, (*data)->win);
    if ((*data)->mlx)
        (mlx_destroy_display((*data)->mlx), free((*data)->mlx));
}

void    free_data(t_data **data)
{
    if (!data || !*data)
        return;
    if ((*data)->img.path_NO)
        free((*data)->img.path_NO);
    if ((*data)->img.path_SO)
        free((*data)->img.path_SO);
    if ((*data)->img.path_WE)
        free((*data)->img.path_WE);
    if ((*data)->img.path_EA)
        free((*data)->img.path_EA);
    if ((*data)->map->tab)
        free_tab((*data)->map->tab);
    if ((*data)->map->tmp)
        free_tab((*data)->map->tmp);
    free((*data)->map);
    (free_data2(data), free(*data));
    *data = NULL;
}

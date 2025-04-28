/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:40:10 by jojo              #+#    #+#             */
/*   Updated: 2025/04/28 16:35:14 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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

void    free_data(t_data **data)
{
    if (!data || !*data)
        return;
    if ((*data)->img.NO)
        free((*data)->img.NO);
    if ((*data)->img.SO)
        free((*data)->img.SO);
    if ((*data)->img.WE)
        free((*data)->img.WE);
    if ((*data)->img.EA)
        free((*data)->img.EA);
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
    free(*data);
    *data = NULL;
}

void    ft_is_good_format(char *file)
{
    int len;

    len = ft_strlen(file) - 1;
    if (file[len] != 'b'
        || file[len - 1] != 'u'
        || file[len - 2] != 'c'
        || file[len - 3] != '.')
        (error("error: file: format is not on .cub !\n"), exit(1));
    return ;
}

int main(int ac, char **av)
{
    t_data  *data;

    if (ac != 2)
        (error("error: exec: arguments format './cub3D maps/.cub'\n"), exit(1));
    ft_is_good_format(av[1]);
    data = init_data();
    ft_init_data(&data, av[1]);
    free_data(&data);
}
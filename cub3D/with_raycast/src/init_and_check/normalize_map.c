/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:59 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/06 14:24:27 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int get_len(char **tab)
{
    int i;
    int new_len;
    int old_len;

    i = 0;
    new_len = 0;
    old_len = 0;
    while (tab[i])
    {
        new_len = (int)ft_strlen(tab[i]);
        if (new_len > old_len)
            old_len = new_len;
        i++;
    }
    return (old_len);
}

void normalize_map(t_data **data)
{
    int len_y = ft_lenTab((*data)->map->tab);
    int len_x = get_len((*data)->map->tab);
    char **new_tab = ft_calloc(len_y + 1, sizeof(char *));
    for (int i = 0; i < len_y; i++)
    {
        new_tab[i] = ft_calloc(len_x + 1, sizeof(char));
        int j = 0;
        while ((*data)->map->tab[i][j])
        {
            new_tab[i][j] = (*data)->map->tab[i][j];
            j++;
        }
        while (j < len_x) // remplissage avec des espaces
        {
            new_tab[i][j] = ' ';
            j++;
        }
    }
    free_tab((*data)->map->tab); // libère l'ancienne map
    (*data)->map->tab = new_tab;
    (*data)->map->len_x = len_x;
    (*data)->map->len_y = len_y;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocTab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:30:27 by jotudela          #+#    #+#             */
/*   Updated: 2025/04/29 12:36:53 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

static int  ft_lenTab(char **tab)
{
    int i;

    if (!tab || !*tab)
        return (0);
    i = 0;
    while (tab[i])
        i++;
    return (i);
}

static int  ft_allocFirst(t_data **data, char *line)
{
    char    **new_tab;

    new_tab = ft_calloc(sizeof(char *), 2);
    if (!new_tab)
        return (-1);
    new_tab[0] = ft_strdup(line);
    new_tab[1] = NULL;
    (*data)->map->tab = new_tab;
    return (0);
}

int    ft_reallocTab(t_data **data, char *line)
{
    char    **new_tab;
    int     len_tab;
    int     i;

    if (!(*data)->map->tab)
        return (ft_allocFirst(data, line));
    len_tab = ft_lenTab((*data)->map->tab) + 2;
    new_tab = ft_calloc(sizeof(char *), len_tab);
    if (!new_tab)
        return (-1);
    i = 0;
    while ((*data)->map->tab[i])
    {
        new_tab[i] = ft_strdup((*data)->map->tab[i]);
        if (!new_tab[i])
            return (free_tab(new_tab), -1);
        i++;
    }
    new_tab[i++] = ft_strdup(line);
    new_tab[i] = NULL;
    free_tab((*data)->map->tab);
    (*data)->map->tab = new_tab;
    return (0);
}

int     ft_coppyTab(t_data **data)
{
    int len_tab;
    int i;

    if (!(*data)->map->tab)
        return (-1);
    len_tab = ft_lenTab((*data)->map->tab) + 1;
    (*data)->map->tmp = ft_calloc(sizeof(char *), len_tab);
    if (!(*data)->map->tmp)
        return (-1);
    i = 0;
    while ((*data)->map->tab[i])
    {
        (*data)->map->tmp[i] = ft_strdup((*data)->map->tab[i]);
        if (!(*data)->map->tmp[i])
            return (-1);
        i++;
    }
    (*data)->map->tmp[i] = NULL;
    return (0);
}

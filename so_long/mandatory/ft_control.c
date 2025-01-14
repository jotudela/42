/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:56 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/14 16:16:21 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
    On doit verifier si la map est un rectanle, 'OK'
    si la map contient une seule sortie, au moins un item, et une seule position de depart, 'OK'
    si la map est bien entoure et ferne par des murs, 'OK'
    si il y a pas de caractere inconnue, 'OK'
    si toutes les ligne font la meme logueur, 'OK'
    et si il y a un chemin valide.
*/

t_control   *new_su(void)
{
    t_control   *su;

    su = ft_calloc(sizeof(*su), 1);
    if (!su)
        return (NULL);
    su->x = 0;
    su->y = 0;
    su->item = 0;
    su->exit = 0;
    su->player = 0;
    su->type_error = -1;
    return (su);
}

static int  ft_lstlen(t_map *map)
{
    int i;

    i = 0;
    while (map)
    {
        ++i;
        map = map->next;
    }
    return (i);
}

static int  is_rectangle(t_map *map, t_control *su)
{
    su->x = map->len_line;
    su->y = ft_lstlen(map);
    if (su->x == su->y)
    {
        su->type_error = 1;
        return (1);
    }
    return (0);
}

static int  is_CEP(t_map *map, t_control *su)
{
    while (map)
    {
        su->item += map->item;
        su->exit += map->exit;
        su->player += map->player;
        map = map->next;  
    }
    if (su->item == 0)
    {
        su->type_error = 2;
        return (1);
    }
    else if (su->exit != 1)
    {
        su->type_error = 22;
        return (1);
    }
    else if (su->player != 1)
    {
        su->type_error = 23;
        return (1);
    }
    return (0);
}

static int  char_is_invalid(t_map *map, t_control *su)
{
    int i;

    while (map)
    {
        i = 0;
        while (map->line[i] && i < map->len_line)
        {
            if (map->line[i] != '0' && map->line[i] != '1' && map->line[i] != 'C' && map->line[i] != 'E' && map->line[i] != 'P')
            {
                su->type_error = 4;
                return (1);
            }
            i++;
        }
        map = map->next;
    }
    return (0);
}

static int  good_outline2(t_map *map, t_control *su)
{
    int i;

    i = 0;
    while (map->line[i] && i < map->len_line)
    {
        if (map->line[i] != '1')
        {
            su->type_error = 3;
            return (1);
        }
        i++;
    }
    return (0);
}

static int  good_outline(t_map *map, t_control *su)
{
    if (good_outline2(map, su) == 1)
        return (1);
    while (map->next && map->next->next != NULL)
    {
        if (map->line[0] != '1' || map->line[ft_strlen(map->line) - 2] != '1')
        {
            su->type_error = 3;
            return (1);
        }
        map = map->next;
    }
    if (good_outline2(map->next, su) == 1)
        return (1);
    return (0);
}

static int  good_len_line(t_map *map, t_control *su)
{
    int tmp;

    tmp = map->len_line;
    while (map->next)
    {
        if (tmp != map->len_line)
        {
            su->type_error = 5;
            return (1);
        }
        map = map->next;
    }
    return (0);
}

void    ft_suclear(t_control **su)
{
    if (!*su)
        return ;
    free((*su));
    *su = NULL;
}

int ft_control(t_map *map, t_control *su)
{
    if (is_rectangle(map, su) == 1)
        return (1);
    if (is_CEP(map, su) == 1)
        return (1);
    if (good_outline(map, su) == 1)
        return (1);
    if (char_is_invalid(map, su) == 1)
        return (1);
    if (good_len_line(map, su) == 1)
        return (1);
    return (0);
}

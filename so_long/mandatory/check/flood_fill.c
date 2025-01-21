/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:55:38 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 14:22:54 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	flood_fill(t_map *map, t_control *control, int x, int y)
{
	t_map	*current_line;
	int		i;
	char	current;

	current_line = map;
	i = 0;
	while (i++ < y && current_line)
		current_line = current_line->next;
	if (!current_line || x < 0 || x >= current_line->len_line
		|| current_line->tmp[x] == 'V' || current_line->tmp[x] == '1')
		return ;
	current = current_line->tmp[x];
	if (current == 'C')
		control->item++;
	else if (current == 'E')
		control->exit++;
	else if (current == 'P')
		control->player++;
	current_line->tmp[x] = 'V';
	flood_fill(map, control, x + 1, y);
	flood_fill(map, control, x - 1, y);
	flood_fill(map, control, x, y + 1);
	flood_fill(map, control, x, y - 1);
}

static void	find_xy(t_map *map, t_control *su)
{
	int	i;
	int	j;

	j = 0;
	while (map)
	{
		i = 0;
		while (map->line[i] != '\0')
		{
			if (map->line[i] == 'P')
			{
				su->x = i;
				su->y = j;
				return ;
			}
			i++;
		}
		j++;
		map = map->next;
	}
}

int	path_valid(t_map *map, t_control *su)
{
	int	tmp;

	tmp = su->item;
	su->item = 0;
	su->exit = 0;
	su->player = 0;
	find_xy(map, su);
	flood_fill(map, su, su->x, su->y);
	if (su->item != tmp || su->exit == 0 || su->player == 0)
	{
		su->type_error = 7;
		return (1);
	}
	return (0);
}

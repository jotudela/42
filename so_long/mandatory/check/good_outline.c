/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_outline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:19:39 by jotudela          #+#    #+#             */
/*   Updated: 2025/06/06 10:14:12 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	good_outline2(t_map *map, t_control *su)
{
	int	i;

	i = 0;
	while (map->line[i] && i <= map->len_line)
	{
		if (map->line[i] != '1')
		{
			su->type_error = 4;
			return (1);
		}
		i++;
	}
	return (0);
}

int	good_outline(t_map *map, t_control *su)
{
	if (good_outline2(map, su) == 1)
		return (1);
	while (map->next && map->next->next != NULL)
	{
		if (map->line[0] != '1' || map->line[map->len_line - 1] != '1')
		{
			su->type_error = 4;
			return (1);
		}
		map = map->next;
	}
	if (good_outline2(map->next, su) == 1)
		return (1);
	return (0);
}

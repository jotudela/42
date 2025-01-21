/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_is_invalid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:16:46 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 14:13:56 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	char_is_invalid(t_map *map, t_control *su)
{
	int	i;

	while (map)
	{
		i = 0;
		while (map->line[i] && i < map->len_line)
		{
			if (map->line[i] != '0' && map->line[i] != '1'
				&& map->line[i] != 'C'
				&& map->line[i] != 'E' && map->line[i] != 'P')
			{
				su->type_error = 5;
				return (1);
			}
			i++;
		}
		map = map->next;
	}
	return (0);
}

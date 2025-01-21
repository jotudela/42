/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:35:10 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 15:37:22 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	position(t_data *data, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map)
	{
		x = 0;
		while (map->line[x])
		{
			if (map->line[x] == 'P' || map->line[x] == '2')
			{
				data->player.x = x;
				data->player.y = y;
				return ;
			}
			x++;
		}
		y++;
		map = map->next;
	}
}

void	find_e(t_map *map, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (map)
	{
		i = 0;
		while (map->line[i] != '\0')
		{
			if (map->line[i] == 'E')
			{
				data->player.xe = i;
				data->player.ye = j;
				return ;
			}
			i++;
		}
		j++;
		map = map->next;
	}
}

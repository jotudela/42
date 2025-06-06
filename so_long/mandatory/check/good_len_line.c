/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_len_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:21:03 by jotudela          #+#    #+#             */
/*   Updated: 2025/06/06 11:13:48 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	good_len_line(t_map *map, t_control *su)
{
	int	tmp;

	tmp = map->len_line;
	while (map)
	{
		if (tmp != map->len_line)
		{
			su->type_error = 6;
			return (1);
		}
		map = map->next;
	}
	return (0);
}

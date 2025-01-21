/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:13:42 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 14:37:37 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_lstlen(t_map *map)
{
	int	i;

	i = 0;
	while (map)
	{
		++i;
		map = map->next;
	}
	return (i);
}

int	is_rectangle(t_map *map, t_control *su)
{
	su->x = map->len_line;
	su->y = ft_lstlen(map);
	if (su->x == su->y)
	{
		su->type_error = 2;
		return (1);
	}
	return (0);
}

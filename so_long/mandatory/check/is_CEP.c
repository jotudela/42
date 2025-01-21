/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_CEP.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:15:11 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 14:38:47 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	is_cep(t_map *map, t_control *su)
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
		su->type_error = 3;
		return (1);
	}
	else if (su->exit != 1)
	{
		su->type_error = 32;
		return (1);
	}
	else if (su->player != 1)
	{
		su->type_error = 33;
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:21:05 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 15:29:53 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	print_floor(t_data *data, t_map *map)
{
	print_image(data, data->img.floor, data->player.x, data->player.y);
	map->line[data->player.x] = '0';
}

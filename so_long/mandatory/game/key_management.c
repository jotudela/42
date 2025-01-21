/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:27:31 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 15:38:42 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	gauche(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (i++ < data->player.y && map)
		map = map->next;
	if (map->line[data->player.x - 1] == '1')
		return ;
	if (map->line[data->player.x] == '2')
	{
		print_image(data, data->img.exit1, data->player.x, data->player.y);
		map->line[data->player.x] = 'E';
	}
	else
		print_floor(data, map);
	data->player.x -= 1;
	if (map->line[data->player.x] == 'C')
		data->player.ni += 1;
	if (map->line[data->player.x] == 'E')
		map->line[data->player.x] = '2';
	else
		map->line[data->player.x] = 'P';
	print_image(data, data->img.link, data->player.x, data->player.y);
	data->actions++;
}

static void	droite(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (i++ < data->player.y && map)
		map = map->next;
	if (map->line[data->player.x + 1] == '1')
		return ;
	if (map->line[data->player.x] == '2')
	{
		print_image(data, data->img.exit1, data->player.x, data->player.y);
		map->line[data->player.x] = 'E';
	}
	else
		print_floor(data, map);
	data->player.x += 1;
	if (map->line[data->player.x] == 'C')
		data->player.ni += 1;
	if (map->line[data->player.x] == 'E')
		map->line[data->player.x] = '2';
	else
		map->line[data->player.x] = 'P';
	print_image(data, data->img.link, data->player.x, data->player.y);
	data->actions++;
}

static void	bas(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (i++ < data->player.y && map)
		map = map->next;
	if (map->next->line[data->player.x] == '1')
		return ;
	if (map->line[data->player.x] == '2')
	{
		print_image(data, data->img.exit1, data->player.x, data->player.y);
		map->line[data->player.x] = 'E';
	}
	else
		print_floor(data, map);
	data->player.y += 1;
	if (map->next->line[data->player.x] == 'C')
		data->player.ni += 1;
	if (map->next->line[data->player.x] == 'E')
		map->next->line[data->player.x] = '2';
	else
		map->next->line[data->player.x] = 'P';
	print_image(data, data->img.link, data->player.x, data->player.y);
	data->actions++;
}

static void	haut(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (i++ < data->player.y && map)
		map = map->next;
	if (map->prev->line[data->player.x] == '1')
		return ;
	if (map->line[data->player.x] == '2')
	{
		print_image(data, data->img.exit1, data->player.x, data->player.y);
		map->line[data->player.x] = 'E';
	}
	else
		print_floor(data, map);
	data->player.y -= 1;
	if (map->prev->line[data->player.x] == 'C')
		data->player.ni += 1;
	if (map->prev->line[data->player.x] == 'E')
		map->prev->line[data->player.x] = '2';
	else
		map->prev->line[data->player.x] = 'P';
	print_image(data, data->img.link, data->player.x, data->player.y);
	data->actions++;
}

int	key_press(int keycode, t_data *data)
{
	position(data, *data->map);
	if (keycode == XK_Escape)
	{
		ft_printf("ESCAPE\n");
		close_win(data);
	}
	if (keycode == 97)
		gauche(data, *data->map);
	if (keycode == 100)
		droite(data, *data->map);
	if (keycode == 115)
		bas(data, *data->map);
	if (keycode == 119)
		haut(data, *data->map);
	ft_printf("Numbers of actions : %i\n", data->actions);
	if (data->player.ni == (*(data->su))->item)
	{
		find_e(*data->map, data);
		print_image(data, data->img.exit2, data->player.xe, data->player.ye);
	}
	is_finish(data, *data->map);
	return (0);
}

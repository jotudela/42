/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:50:28 by jojo              #+#    #+#             */
/*   Updated: 2025/05/13 11:22:37 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_cleangnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	is_walkable(t_data *data, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= data->map->len_x || map_y < 0
		|| map_y >= data->map->len_y - 1)
		return (0);
	return (data->map->tab[map_y][map_x] == '0');
}

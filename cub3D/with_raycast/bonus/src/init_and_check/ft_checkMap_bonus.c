/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkMap_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:56:00 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/13 11:23:02 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_find_xy(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data)->map->tmp[i])
	{
		j = 0;
		while ((*data)->map->tmp[i][j])
		{
			if ((*data)->map->tmp[i][j] == 'N'
				|| (*data)->map->tmp[i][j] == 'S'
				|| (*data)->map->tmp[i][j] == 'E'
				|| (*data)->map->tmp[i][j] == 'W')
			{
				(*data)->map->dir = (*data)->map->tmp[i][j];
				(*data)->map->map_x = j;
				(*data)->map->map_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_checkplayer(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	(*data)->map->player = 0;
	while ((*data)->map->tmp[i])
	{
		j = 0;
		while ((*data)->map->tmp[i][j])
		{
			if ((*data)->map->tmp[i][j] == 'N'
				|| (*data)->map->tmp[i][j] == 'S'
				|| (*data)->map->tmp[i][j] == 'E'
				|| (*data)->map->tmp[i][j] == 'W')
				(*data)->map->player++;
			j++;
		}
		i++;
	}
	if ((*data)->map->player > 1)
		return (-1);
	else if ((*data)->map->player <= 0)
		return (-2);
	ft_find_xy(data);
	return (0);
}

int	ft_checkchar(t_data **data)
{
	int	i;
	int	j;

	i = 0;
	while ((*data)->map->tmp[i])
	{
		j = 0;
		while ((*data)->map->tmp[i][j]
			&& (*data)->map->tmp[i][j] != '\n')
		{
			if ((*data)->map->tmp[i][j] != 'N'
				&& (*data)->map->tmp[i][j] != 'S'
				&& (*data)->map->tmp[i][j] != 'E'
				&& (*data)->map->tmp[i][j] != 'W'
				&& (*data)->map->tmp[i][j] != ' '
				&& (*data)->map->tmp[i][j] != '1'
				&& (*data)->map->tmp[i][j] != '0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	flood_fill(t_data **data, int x, int y)
{
	char	**tmp;
	char	current;

	tmp = (*data)->map->tmp;
	if (y < 0 || !tmp[y])
		return (-1);
	if (tmp[y][0] == '\0' || (int)ft_strlen(tmp[y]) <= x || x < 0)
		return (-1);
	current = tmp[y][x];
	if (current == '1' || current == 'V')
		return (0);
	if (current == ' ' || current == '\n' || current == '\0')
		return (-1);
	tmp[y][x] = 'V';
	if (flood_fill(data, x + 1, y) == -1)
		return (-1);
	if (flood_fill(data, x - 1, y) == -1)
		return (-1);
	if (flood_fill(data, x, y + 1) == -1)
		return (-1);
	if (flood_fill(data, x, y - 1) == -1)
		return (-1);
	return (0);
}

int	check_all_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->tmp[i])
	{
		j = 0;
		while (data->map->tmp[i][j])
		{
			if (data->map->tmp[i][j] == '0')
				if (flood_fill(&data, j, i) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

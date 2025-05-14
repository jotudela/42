/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:58:32 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/14 11:33:25 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	ft_get_rgb_value(const char *str, int *index)
{
	int	res;
	int	i;

	res = 0;
	i = *index;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (-1);
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res >= 255)
			return (-1);
		i++;
	}
	if (res < 0 || res > 255)
		return (-1);
	*index = i;
	return (res);
}

static int	parse_rgb_values(char *tmp, int *rgb)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < 3)
	{
		rgb[j] = ft_get_rgb_value(tmp, &i);
		if (rgb[j] == -1)
			return (-1);
		if (j < 2)
		{
			while (tmp[i] == ' ' || tmp[i] == '\t')
				i++;
			if (tmp[i] != ',')
				return (-1);
			i++;
		}
		j++;
	}
	return (0);
}

static void	assign_rgb(t_data **data, int *rgb, int dir)
{
	if (dir == 1)
	{
		(*data)->img.cr = rgb[0];
		(*data)->img.cg = rgb[1];
		(*data)->img.cb = rgb[2];
		(*data)->img.c = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	}
	else
	{
		(*data)->img.fr = rgb[0];
		(*data)->img.fg = rgb[1];
		(*data)->img.fb = rgb[2];
		(*data)->img.f = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	}
}

int	ft_get_rgb(t_data **data, char *line)
{
	int		rgb[3];
	int		i;
	int		dir;
	char	*tmp;

	if (ft_strncmp(line, "F", 1) == 0)
		dir = 0;
	else if (ft_strncmp(line, "C", 1) == 0)
		dir = 1;
	i = 0;
	while (line[i] == 'F' || line[i] == 'C'
		|| line[i] == ' ' || line[i] == '\t')
		i++;
	tmp = ft_strtrim(line + i, " \t");
	if (!tmp)
		return (-1);
	if (parse_rgb_values(tmp, rgb) == -1)
		return (free(tmp), -1);
	assign_rgb(data, rgb, dir);
	return (free(tmp), 0);
}

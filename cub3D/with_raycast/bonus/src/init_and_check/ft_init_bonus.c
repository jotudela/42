/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:19:46 by jojo              #+#    #+#             */
/*   Updated: 2025/05/14 10:11:41 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	check_info(t_data **data, int mod)
{
	if (mod == 0)
	{
		if ((*data)->img.path_no && (*data)->img.path_so
			&& (*data)->img.path_we && (*data)->img.path_ea
			&& (*data)->img.f && (*data)->img.c)
			return (0);
		return (-1);
	}
	if (mod == 1)
	{
		if (ft_checkchar(data) == -1)
			(free_data(data), error("Error\nparsing:"
					" one or more char is invalid\n"), exit(1));
		if (check_all_map(*data) == -1)
			(free_data(data), error("Error\nparsing:"
					" map is invalid\n"), exit(1));
	}
	return (0);
}

static char	*ft_skipemptyline(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[0] == '\n' && ft_strlen(line) == 1)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		else
			return (line);
	}
	return (NULL);
}

static int	ft_take_data2(t_data **data, int fd)
{
	char	*line;

	line = ft_skipemptyline(fd);
	while (line != NULL)
	{
		if (line[0] == '\n' && ft_strlen(line) == 1)
		{
			free(line);
			line = ft_skipemptyline(fd);
			if (line != NULL)
				return (free(line), ft_cleangnl(fd), -1);
		}
		if (ft_realloctab(data, line) == -1)
			return (free(line), -1);
		free(line);
		line = get_next_line(fd);
	}
	if (!(*data)->map->tab)
		return (-1);
	return (0);
}

static int	ft_take_data(t_data **data, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i])
		{
			if (ft_strncmp(line + i, "NO", 2) == 0
				|| ft_strncmp(line + i, "SO", 2) == 0
				|| ft_strncmp(line + i, "WE", 2) == 0
				|| ft_strncmp(line + i, "EA", 2) == 0)
				ft_get_texture_path(data, line + i);
			else if (ft_strncmp(line + i, "F", 1) == 0
				|| ft_strncmp(line + i, "C", 1) == 0)
				ft_get_rgb(data, line + i);
			i++;
		}
		if (check_info(data, 0) == 0)
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (-1);
}

int	ft_init_data(t_data **data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		(free_data(data), error("Error\nfile: can't open file !\n"), exit(1));
	if (ft_take_data(data, fd) == -1)
		(free_data(data), error("Error\nparsing: "
				"take data 1 fail\n"), close(fd), exit(1));
	if ((*data)->img.c == (*data)->img.f)
		(free_data(data), error("Error\nCeilling "
				"and floor have same color !\n"), close(fd), exit(1));
	if (ft_take_data2(data, fd) == -1)
		(free_data(data), error("Error\nparsing: "
				"take data 2 fail\n"), close(fd), exit(1));
	close(fd);
	if (ft_coppytab(data) == -1)
		(free_data(data), error("Error\nparsing: fatal\n"), exit(1));
	fd = ft_checkplayer(data);
	if (fd == -1)
		(free_data(data), error("Error\nparsing: "
				"too many player in map\n"), exit(1));
	else if (fd == -2)
		(free_data(data), error("Error\nparsing: no player in map\n"), exit(1));
	(check_info(data, 1), normalize_map(data));
	return (0);
}

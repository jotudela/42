/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:04:23 by jotudela          #+#    #+#             */
/*   Updated: 2025/06/06 10:29:27 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_closefds(void)
{
	int	fd;

	fd = 2;
	while (fd < 1024)
	{
		close(fd);
		fd++;
	}
}

static void	ft_veriflst(t_map **li)
{
	if (!(*li) || !li)
	{
		ft_mapclear(li);
		ft_closefds();
		ft_putstr_fd("Error\nList corrupted !", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_update(t_map *map)
{
	int	i;

	if (!map)
		return ;
	while (map)
	{
		i = 0;
		while (i < map->len_line && map->line[i])
		{
			if (map->line[i] == '0')
				map->empty += 1;
			else if (map->line[i] == '1')
				map->wall += 1;
			else if (map->line[i] == 'C')
				map->item += 1;
			else if (map->line[i] == 'E')
				map->exit += 1;
			else if (map->line[i] == 'P')
				map->player += 1;
			i++;
		}
		map = map->next;
	}
}

t_map	*ft_init(char *file)
{
	int		fd;
	char	*tmp;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	tmp = get_next_line(fd);
	if (!tmp)
		return (close(fd), NULL);
	map = ft_lstnew(tmp, ft_strlen(tmp) - 1);
	ft_veriflst(&map);
	free(tmp);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		ft_lstadd_back(&map, ft_lstnew(tmp, ft_strlen(tmp) - 1));
		free(tmp);
		ft_veriflst(&map);
	}
	return (close(fd), free(tmp), map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:40:18 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/14 17:20:49 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_map(t_map *map)
{
	while (map)
	{
		ft_printf("%s", map->line);
		ft_printf("empty:%i\nwall:%i\nitem:%i\nexit:%i\nplayer:%i", map->empty, map->wall, map->item, map->exit, map->player);
		if (map->next != NULL)
			ft_printf("\n\n");
		map = map->next;
	}
}

static void	print_error(int type_error)
{
	if (type_error == 1)
		write(2, "Error\nThe file is not on format .ber !", 39);
	else if (type_error == 2)
		write(2, "Error\nThe map is not rectangular !", 34);
	else if (type_error == 3)
		write(2, "Error\nThere are no item !", 26);
	else if (type_error == 32)
		write(2, "Error\nThere are no exit !", 26);
	else if (type_error == 33)
		write(2, "Error\nThere are no player !", 28);
	else if (type_error == 4)
		write(2, "Error\nThe outline is not valid !", 33);
	else if (type_error == 5)
		write(2, "Error\nThere is a character invalid !", 37);
	else if (type_error == 6)
		write(2, "Error\nThere is a line who has not a good size !", 48);
}

int	main(int ac, char **av)
{
	t_map	*map;
	t_control	*su;
	
	if (ft_strnstr(av[1], ".ber", ft_strlen(av[1])) == NULL)
		return (print_error(1), 0);
	map = ft_init(av[1]);
	if (!map)
		return (0);
	ft_update(map);
	su = new_su();
	if (!su)
		return (ft_mapclear(&map), 0);
	if (ft_control(map, su) == 1)
	{
		print_error(su->type_error);
		ft_mapclear(&map);
		ft_suclear(&su);
		exit(EXIT_FAILURE);
	}
	ft_mapclear(&map);
	ft_suclear(&su);
}

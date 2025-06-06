/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:40:18 by jotudela          #+#    #+#             */
/*   Updated: 2025/06/06 10:16:29 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	print_error(int type_error)
{
	if (type_error == 0)
		write(2, "Error\nThe number of arguments is invalid !", 43);
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
	else if (type_error == 7)
		write(2, "Error\nThe game can't be win !", 30);
	else if (type_error == 8)
		ft_putstr_fd("Error\nCan't malloc !", 2);
}

int	ft_good_format(char *file)
{
	int	i;

	i = ft_strlen(file) - 1;
	if (file[i] != 'r')
		return (1);
	if (file[i - 1] != 'e')
		return (1);
	if (file[i - 2] != 'b')
		return (1);
	if (file[i - 3] != '.')
		return (1);
	return (0);
}

void	game(t_map **map, t_control **su)
{
	so_long(map, su);
}

int	main(int ac, char **av)
{
	t_map		*map;
	t_control	*su;

	if (ac != 2)
		return (print_error(0), 0);
	if (ft_good_format(av[1]) == 1)
		return (print_error(1), 0);
	map = ft_init(av[1]);
	if (!map)
		return (print_error(8), 0);
	ft_update(map);
	su = new_su();
	if (!su)
		return (ft_mapclear(&map), 0);
	if (ft_control(map, su) == 1)
	{
		print_error(su->type_error);
		ft_mapclear(&map);
		ft_suclear(&su);
		return (0);
	}
	game(&map, &su);
}

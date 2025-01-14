/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:40:18 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/14 11:25:29 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	print_map(t_map *map)
{
	while (map)
	{
		ft_printf("%s", map->line);
		map = map->next;
	}
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = ft_init(av[1]);
	print_map(map);
	ft_printf("%i\n", map->len_line);
	ft_lstclear(&map);
}

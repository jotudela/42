/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:41:59 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 09:13:27 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	get_len(char **tab)
{
	int	i;
	int	new_len;
	int	old_len;

	i = 0;
	new_len = 0;
	old_len = 0;
	while (tab[i])
	{
		new_len = (int)ft_strlen(tab[i]);
		if (new_len > old_len)
			old_len = new_len;
		i++;
	}
	return (old_len);
}

static void	asign_tab(t_data **data, char **new_tab, int len_x, int len_y)
{
	free_tab((*data)->map->tab);
	(*data)->map->tab = new_tab;
	(*data)->map->len_x = len_x;
	(*data)->map->len_y = len_y;
}

void	normalize_map(t_data **data)
{
	int		len_y;
	int		len_x;
	int		i;
	int		j;
	char	**new_tab;

	len_y = ft_lentab((*data)->map->tab);
	len_x = get_len((*data)->map->tab);
	new_tab = ft_calloc(len_y + 1, sizeof(char *));
	i = 0;
	while (i < len_y)
	{
		new_tab[i] = ft_calloc(len_x + 1, sizeof(char));
		j = -1;
		while ((*data)->map->tab[i][++j])
			new_tab[i][j] = (*data)->map->tab[i][j];
		while (j < len_x)
		{
			new_tab[i][j] = ' ';
			j++;
		}
		i++;
	}
	asign_tab(data, new_tab, len_x, len_y);
}

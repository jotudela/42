/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free_data_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:52:04 by jotudela          #+#    #+#             */
/*   Updated: 2025/06/25 14:34:14 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = ft_calloc(sizeof(*data), 1);
	if (!data)
		(error("error: allocation fail\n"), exit(1));
	data->mlx = NULL;
	data->win = NULL;
	data->map = ft_calloc(sizeof(t_map), 1);
	if (!data->map)
		(error("error: allocation fail\n"), free(data), exit(1));
	data->keys.a = 0;
	data->keys.d = 0;
	data->keys.w = 0;
	data->keys.s = 0;
	data->keys.left = 0;
	data->keys.right = 0;
	return (data);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static void	free_data2(t_data **data)
{
	if ((*data)->img.img_ptr)
		mlx_destroy_image((*data)->mlx, (*data)->img.img_ptr);
	if ((*data)->img.no.img_ptr)
		mlx_destroy_image((*data)->mlx, (*data)->img.no.img_ptr);
	if ((*data)->img.so.img_ptr)
		mlx_destroy_image((*data)->mlx, (*data)->img.so.img_ptr);
	if ((*data)->img.we.img_ptr)
		mlx_destroy_image((*data)->mlx, (*data)->img.we.img_ptr);
	if ((*data)->img.ea.img_ptr)
		mlx_destroy_image((*data)->mlx, (*data)->img.ea.img_ptr);
	if ((*data)->mlx && (*data)->win)
		mlx_destroy_window((*data)->mlx, (*data)->win);
	if ((*data)->mlx)
		(mlx_destroy_display((*data)->mlx), free((*data)->mlx));
}

void	free_data(t_data **data)
{
	if (!data || !*data)
		return ;
	if ((*data)->img.path_no)
		free((*data)->img.path_no);
	if ((*data)->img.path_so)
		free((*data)->img.path_so);
	if ((*data)->img.path_we)
		free((*data)->img.path_we);
	if ((*data)->img.path_ea)
		free((*data)->img.path_ea);
	if ((*data)->map->tab)
		free_tab((*data)->map->tab);
	if ((*data)->map->tmp)
		free_tab((*data)->map->tmp);
	free((*data)->map);
	(free_data2(data), free(*data));
	*data = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:30:03 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 14:46:53 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.exit2);
	mlx_destroy_image(data->mlx, data->img.exit1);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.tree);
	mlx_destroy_image(data->mlx, data->img.floor);
	mlx_destroy_image(data->mlx, data->img.link);
	mlx_destroy_image(data->mlx, data->img.triforce);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_mapclear(data->map);
	ft_suclear(data->su);
	exit(0);
}

int	close_win2(t_data *data)
{
	if (data->img.exit2)
		mlx_destroy_image(data->mlx, data->img.exit2);
	if (data->img.exit1)
		mlx_destroy_image(data->mlx, data->img.exit1);
	if (data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (data->img.tree)
		mlx_destroy_image(data->mlx, data->img.tree);
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.link)
		mlx_destroy_image(data->mlx, data->img.link);
	if (data->img.triforce)
		mlx_destroy_image(data->mlx, data->img.triforce);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_mapclear(data->map);
	ft_suclear(data->su);
	exit(0);
}

int	close_cross(t_data *data)
{
	ft_printf("ESCAPE\n");
	close_win(data);
	return (0);
}

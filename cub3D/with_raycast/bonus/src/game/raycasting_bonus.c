/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:04:45 by jotudela          #+#    #+#             */
/*   Updated: 2025/06/25 14:37:37 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	calcul_pos(t_data *data, t_raycast *r, int x)
{
	r->camerax = 2 * x / (float)data->img.img_x - 1;
	r->raydirx = data->player.dirx + data->player.planex * r->camerax;
	r->raydiry = data->player.diry + data->player.planey * r->camerax;
	r->mapx = (int)data->player.x;
	r->mapy = (int)data->player.y;
	r->deltadistx = fabs(1 / r->raydirx);
	r->deltadisty = fabs(1 / r->raydiry);
	r->hit = 0;
}

static void	calcul_camera(t_data *data, t_raycast *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (data->player.x - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - data->player.x) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (data->player.y - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - data->player.y) * r->deltadisty;
	}
}

static void	search_wall(t_data *data, t_raycast *r)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (r->mapy < 0 || r->mapy >= data->map->len_y
			|| r->mapx < 0 || r->mapx >= data->map->len_x
			|| data->map->tab[r->mapy][r->mapx] == '1'
			|| data->map->tab[r->mapy][r->mapx] == ' ')
			r->hit = 1;
	}
}

static void	calcul_direction(t_data *data, t_raycast *r)
{
	if (r->side == 0)
		r->perpwalldist = (r->mapx - data->player.x
				+ (1 - r->stepx) / 2) / r->raydirx;
	else
		r->perpwalldist = (r->mapy - data->player.y
				+ (1 - r->stepy) / 2) / r->raydiry;
	r->lineheight = (int)(data->img.img_y / r->perpwalldist);
	r->drawstart = -r->lineheight / 2 + data->img.img_y / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + data->img.img_y / 2;
	if (r->drawend >= data->img.img_y)
		r->drawend = data->img.img_y - 1;
}

void	raycasting(t_data *data)
{
	t_tex_info	*tex;
	t_raycast	r;
	int			x;

	x = 0;
	tex = NULL;
	ft_draw_img(&data);
	while (x < data->img.img_x)
	{
		calcul_pos(data, &r, x);
		calcul_camera(data, &r);
		search_wall(data, &r);
		calcul_direction(data, &r);
		which_tex(data, &r, &tex);
		r.texx = (int)(r.wallx * tex->width);
		if (tex == &data->img.we)
			r.texx = tex->width - r.texx - 1;
		else if (tex == &data->img.so)
			r.texx = tex->width - r.texx - 1;
		draw_walls(data, x, tex, r);
		x++;
	}
	render_map_to_final_image(data, data->map->tab, 30);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
}

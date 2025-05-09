/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:40:11 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 18:13:47 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	which_tex(t_data *data, t_raycast *r, t_tex_info **tex)
{
	if (r->side == 0)
	{
		if (r->raydirx > 0)
			*tex = &data->img.ea;
		else
			*tex = &data->img.we;
	}
	else
	{
		if (r->raydiry > 0)
			*tex = &data->img.so;
		else
			*tex = &data->img.no;
	}
	if (r->side == 0)
		r->wallx = data->player.y + r->perpwalldist * r->raydiry;
	else
		r->wallx = data->player.x + r->perpwalldist * r->raydirx;
	r->wallx -= floor(r->wallx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_textures_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:11:26 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/13 11:27:30 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static int	xpm_to_img(t_tex_info *tex, char *path, t_data *data)
{
	tex->img_ptr = mlx_xpm_file_to_image(data->mlx,
			path,
			&tex->width,
			&tex->height);
	if (!tex->img_ptr)
		return (-1);
	tex->addr = mlx_get_data_addr(tex->img_ptr,
			&tex->bits_per_pixel,
			&tex->size_line,
			&tex->endian);
	if (!tex->addr)
		return (-1);
	return (0);
}

int	generate_textures(t_data *data)
{
	if (xpm_to_img(&data->img.no, data->img.path_no, data) < 0
		|| xpm_to_img(&data->img.so, data->img.path_so, data) < 0
		|| xpm_to_img(&data->img.we, data->img.path_we, data) < 0
		|| xpm_to_img(&data->img.ea, data->img.path_ea, data) < 0)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:01:54 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/13 11:24:18 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

static void	ft_verif_is_allocated(t_data **data, int dir)
{
	if ((*data)->img.path_no && dir == 0)
		free((*data)->img.path_no);
	else if ((*data)->img.path_so && dir == 1)
		free((*data)->img.path_so);
	else if ((*data)->img.path_we && dir == 2)
		free((*data)->img.path_we);
	else if ((*data)->img.path_ea && dir == 3)
		free((*data)->img.path_ea);
}

void	ft_get_texture_path(t_data **data, char *line)
{
	int	dir;

	dir = -1;
	if (ft_strncmp(line, "NO", 2) == 0)
		dir = 0;
	else if (ft_strncmp(line, "SO", 2) == 0)
		dir = 1;
	else if (ft_strncmp(line, "WE", 2) == 0)
		dir = 2;
	else if (ft_strncmp(line, "EA", 2) == 0)
		dir = 3;
	ft_verif_is_allocated(data, dir);
	if (dir == 0)
		(*data)->img.path_no = ft_strtrim(line + 2, " \t\n");
	else if (dir == 1)
		(*data)->img.path_so = ft_strtrim(line + 2, " \t\n");
	else if (dir == 2)
		(*data)->img.path_we = ft_strtrim(line + 2, " \t\n");
	else if (dir == 3)
		(*data)->img.path_ea = ft_strtrim(line + 2, " \t\n");
}

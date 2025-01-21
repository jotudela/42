/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:32:56 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 14:40:56 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_control	*new_su(void)
{
	t_control	*su;

	su = ft_calloc(sizeof(*su), 1);
	if (!su)
		return (NULL);
	su->x = 0;
	su->y = 0;
	su->item = 0;
	su->exit = 0;
	su->player = 0;
	su->type_error = -1;
	return (su);
}

void	ft_suclear(t_control **su)
{
	if (!*su)
		return ;
	free((*su));
	*su = NULL;
}

int	ft_control(t_map *map, t_control *su)
{
	if (is_rectangle(map, su) == 1)
		return (1);
	if (is_cep(map, su) == 1)
		return (1);
	if (good_outline(map, su) == 1)
		return (1);
	if (char_is_invalid(map, su) == 1)
		return (1);
	if (good_len_line(map, su) == 1)
		return (1);
	if (path_valid(map, su) == 1)
		return (1);
	return (0);
}

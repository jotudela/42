/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isGoodFormat_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:53:48 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/13 11:23:34 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d_bonus.h"

void	ft_is_good_format(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (file[len] != 'b'
		|| file[len - 1] != 'u'
		|| file[len - 2] != 'c'
		|| file[len - 3] != '.'
		|| len == 3)
		(error("error: file: format is not on .cub !\n"), exit(1));
	return ;
}

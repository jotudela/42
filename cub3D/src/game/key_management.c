/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:24:16 by jotudela          #+#    #+#             */
/*   Updated: 2025/04/30 12:49:56 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int    key_press(int keycode, t_data *data)
{
    if (keycode == XK_Escape)
        (printf("Bye !\n"), free_data(&data), exit(0));
    return (0);
}

int    close_cross(t_data *data)
{
	printf("Bye !\n");
    free_data(&data);
    return (0);
}
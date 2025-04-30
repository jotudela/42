/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:24:16 by jotudela          #+#    #+#             */
/*   Updated: 2025/04/30 22:12:48 by jojo             ###   ########.fr       */
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
	ft_printf("Bye !\n");
    free_data(&data);
    exit(0);
}
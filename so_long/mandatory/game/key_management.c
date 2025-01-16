/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:27:31 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/16 14:28:13 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int Key_press(int keycode, t_data *data)
{
    if (keycode == XK_Escape)
    {
        ft_printf("ESCAPE\n");
        close_win(data);
    }
    else if (keycode == 97)
        ft_printf("A\n");
    else if (keycode == 100)
        ft_printf("D\n");
    else if (keycode == 115)
        ft_printf("S\n");
    else if (keycode == 119)
        ft_printf("W\n");
    return (0);
}

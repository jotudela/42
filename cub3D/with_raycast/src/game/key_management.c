/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:24:16 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/05 14:33:09 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void clear_window(t_data *data, int width, int height)
{
    void *clear_img = mlx_new_image(data->mlx, width, height);
    mlx_put_image_to_window(data->mlx, data->win, clear_img, 0, 0);
    mlx_destroy_image(data->mlx, clear_img);
}

void draw_pause_menu(t_data *data)
{
    mlx_string_put(data->mlx, data->win, data->img.img_x / 2 - 40, data->img.img_y / 2 - 30, 0xFFFFFF, "Continuer (1)");
    mlx_string_put(data->mlx, data->win, data->img.img_x / 2 - 30, data->img.img_y / 2 + 10, 0xFFFFFF, "Quitter (2)");
}

static void handle_movement(int keycode, t_data *data)
{
    if (keycode == 97) // A
    {
        data->keys.a = 1;
        data->player.x -= 0.1;
    }
    else if (keycode == 100) // D
    {
        data->keys.d = 1;
        data->player.x += 0.1;
    }
    else if (keycode == 119) // W
    {
        data->keys.w = 1;
        data->player.y -= 0.1;
    }
    else if (keycode == 115) // S
    {
        data->keys.s = 1;
        data->player.y += 0.1;
    }
}

static void handle_game_input(int keycode, t_data *data)
{
    if (keycode == 109) // M
    {
        data->is_map = 1;
        data->is_game = 0;
        clear_window(data, 1280, 720);
        mlx_put_image_to_window(data->mlx, data->win, data->minimap.m_img_ptr, 0, 0);
        draw_player(data, &data->player, 30);
    }
    else if (keycode == XK_Escape)
    {
        data->is_game = 0;
        data->is_paused = 1;
        clear_window(data, 1280, 720);
        draw_pause_menu(data);
    }
    else if (keycode == 97 || keycode == 100 || keycode == 119 || keycode == 115)
    {
        handle_movement(keycode, data);
        mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
        raycasting(data);
    }
}

static void handle_map_input(int keycode, t_data *data)
{
    if (keycode == 109) // M
    {
        data->is_map = 0;
        data->is_game = 1;
        clear_window(data, 1280, 720);
        mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
        raycasting(data);
    }
    else if (keycode == 97 || keycode == 100 || keycode == 119 || keycode == 115)
    {
        handle_movement(keycode, data);
        mlx_put_image_to_window(data->mlx, data->win, data->minimap.m_img_ptr, 0, 0);
        draw_player(data, &data->player, 30);
    }
    else if (keycode == XK_Escape && data->is_paused == 1)
    {
        printf("Bye !\n");
        free_data(&data);
        exit(0);
    }
}

static void handle_pause_input(int keycode, t_data *data)
{
    if (keycode == XK_Escape || keycode == 49) // 1 to resume
    {
        data->is_paused = 0;
        data->is_game = 1;
        clear_window(data, 1280, 720);
        mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
        raycasting(data);
    }
    else if (keycode == 50) // 2 to quit
    {
        printf("Bye !\n");
        free_data(&data);
        exit(0);
    }
}

int key_press(int keycode, t_data *data)
{
    if (data->is_game)
        handle_game_input(keycode, data);
    else if (data->is_map)
        handle_map_input(keycode, data);
    else if (data->is_paused)
        handle_pause_input(keycode, data);
    else if (keycode == 109) // Fallback to open map
    {
        data->is_map = 1;
        clear_window(data, 1280, 720);
        mlx_put_image_to_window(data->mlx, data->win, data->minimap.m_img_ptr, 0, 0);
        draw_player(data, &data->player, 30);
    }
    else if (keycode == XK_Escape)
    {
        data->is_paused = 1;
        clear_window(data, 1280, 720);
        draw_pause_menu(data);
    }
    return 0;
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 119)
		data->keys.w = 0;
	if (keycode == 97)
		data->keys.a = 0;
	if (keycode == 115)
		data->keys.s = 0;
	if (keycode == 100)
		data->keys.d = 0;
    return (0);
}

int    close_cross(t_data *data)
{
	ft_printf("Bye !\n");
    free_data(&data);
    exit(0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:24:16 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/05 18:39:25 by jotudela         ###   ########.fr       */
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

static void	update_camera(t_data *data)
{
	double rotSpeed = 0.05;
	if (data->keys.left)
	{
		double oldDirX = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(-rotSpeed) - data->player.dirY * sin(-rotSpeed);
		data->player.dirY = oldDirX * sin(-rotSpeed) + data->player.dirY * cos(-rotSpeed);
		double oldPlaneX = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(-rotSpeed) - data->player.planeY * sin(-rotSpeed);
		data->player.planeY = oldPlaneX * sin(-rotSpeed) + data->player.planeY * cos(-rotSpeed);
	}
	if (data->keys.right)
	{
		double oldDirX = data->player.dirX;
		data->player.dirX = data->player.dirX * cos(rotSpeed) - data->player.dirY * sin(rotSpeed);
		data->player.dirY = oldDirX * sin(rotSpeed) + data->player.dirY * cos(rotSpeed);
		double oldPlaneX = data->player.planeX;
		data->player.planeX = data->player.planeX * cos(rotSpeed) - data->player.planeY * sin(rotSpeed);
		data->player.planeY = oldPlaneX * sin(rotSpeed) + data->player.planeY * cos(rotSpeed);
	}
}

static int is_walkable(t_data *data, double x, double y)
{
	int map_x = (int)x;
	int map_y = (int)y;

	// Si la case est '0', c'est une zone vide (walkable)
	if (data->map->tab[map_y][map_x] == '0')
		return (1);
	return (0);
}

static void handle_movement(int keycode, t_data *data)
{
    if (keycode == 119)
    {
        data->keys.w = 1;
        double newX = data->player.x + data->player.dirX * 0.1;
        double newY = data->player.y + data->player.dirY * 0.1;
        if (is_walkable(data, newX, data->player.y))
            data->player.x = newX;
        if (is_walkable(data, data->player.x, newY))
            data->player.y = newY;
    }
    if (keycode == 115)
    {
        data->keys.s = 1;
        double newX = data->player.x - data->player.dirX * 0.1;
        double newY = data->player.y - data->player.dirY * 0.1;
        if (is_walkable(data, newX, data->player.y))
            data->player.x = newX;
        if (is_walkable(data, data->player.x, newY))
            data->player.y = newY;
    }
    if (keycode == 97)
    {
        data->keys.a = 1;
        double newX = data->player.x - data->player.planeX * 0.1;
        double newY = data->player.y - data->player.planeY * 0.1;
        if (is_walkable(data, newX, data->player.y))
            data->player.x = newX;
        if (is_walkable(data, data->player.x, newY))
            data->player.y = newY;
    }
    if (keycode == 100)
    {
        data->keys.d = 1;
        double newX = data->player.x + data->player.planeX * 0.1;
        double newY = data->player.y + data->player.planeY * 0.1;
        if (is_walkable(data, newX, data->player.y))
            data->player.x = newX;
        if (is_walkable(data, data->player.x, newY))
            data->player.y = newY;
    }
    if (keycode == 65361)
    {
	    data->keys.left = 1;
        update_camera(data);
    }
    if (keycode == 65363)
    {
        data->keys.right = 1;
        update_camera(data);
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
    else if (keycode == 97 || keycode == 100 || keycode == 119 || keycode == 115
            || keycode == 65361 || keycode == 65363)
    {
        handle_movement(keycode, data);
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
        mlx_put_image_to_window(data->mlx, data->win, data->img.b_img_ptr, 0, 0);
        raycasting(data);
    }
    else if (keycode == 97 || keycode == 100 || keycode == 119 || keycode == 115
            || keycode == XK_Left || keycode == XK_Right)
    {
        handle_movement(keycode, data);
        update_camera(data);
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
    if (keycode == 65361)
	    data->keys.left = 0;
    if (keycode == 65363)
	    data->keys.right = 0;
    return (0);
}

int    close_cross(t_data *data)
{
	ft_printf("Bye !\n");
    free_data(&data);
    exit(0);
}
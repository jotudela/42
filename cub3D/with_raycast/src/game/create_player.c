/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:26:10 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/05 16:54:46 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_line_thick(void *mlx, void *win, int x1, int y1, int x2, int y2, int color, int thickness)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    int lineLength = sqrt(dx * dx + dy * dy);
    
    // Calculer les vecteurs perpendiculaires pour l'épaisseur
    double perpendicularX = -dy / (double)lineLength;
    double perpendicularY = dx / (double)lineLength;

    // Tracer la ligne principale
    while (1)
    {
        // Dessiner les pixels autour de la ligne principale pour simuler l'épaisseur
        for (int i = -thickness / 2; i <= thickness / 2; i++)
        {
            int newX = x1 + (int)(perpendicularX * i);
            int newY = y1 + (int)(perpendicularY * i);
            mlx_pixel_put(mlx, win, newX, newY, color);  // Dessiner les pixels autour
        }

        if (x1 == x2 && y1 == y2)
            break;
        
        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void draw_player(t_data *mlx, t_player *player, int tile_size)
{
    int size = tile_size * 0.8;
    int offset = (tile_size - size) / 2;

    // Position du joueur
    int px = player->x * tile_size + offset;
    int py = player->y * tile_size + offset;

    // Dessiner le joueur comme un carré rouge
    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            mlx_pixel_put(mlx->mlx, mlx->win, px + x, py + y, 0xFF0000); // Rouge
        }
    }

    // Calculer la position de la direction du joueur
    int dirLength = tile_size / 2;  // Longueur de la ligne de direction
    int directionX = px + size / 2 + (int)(player->dirX * dirLength);
    int directionY = py + size / 2 + (int)(player->dirY * dirLength);

    // Dessiner un trait pour marquer la direction (vert) avec une épaisseur
    int thickness = 5; // Choisis l'épaisseur que tu veux
    draw_line_thick(mlx->mlx, mlx->win, px + size / 2, py + size / 2, directionX, directionY, 0x00FF00, thickness);
}

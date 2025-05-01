/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:23:23 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/01 14:23:49 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    raycast(t_data *data)
{
    int x;
    
    // Pour chaque colonne de l'écran
    for (x = 0; x < WINDOW_WIDTH; x++)
    {
        // 1. Calculer la direction du rayon
        calc_ray_dir(data, x);
        
        // 2. Effectuer l'algorithme DDA pour trouver la distance au mur
        perform_dda(data);
        
        // 3. Calculer la hauteur du mur à dessiner
        calc_wall_height(data);
        
        // 4. Dessiner la colonne avec texture
        draw_textured_line(data, x);
    }
    
    // Dessiner la minimap si activée
    if (data->show_minimap)
        draw_minimap(data);
}

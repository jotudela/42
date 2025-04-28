/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:42:55 by jojo              #+#    #+#             */
/*   Updated: 2025/04/16 18:29:16 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include "../Utils/libft/libft.h"
# include "../Utils/ft_printf/ft_printf.h"
#include "../Utils/get_next_line/get_next_line_bonus.h"
//# include "../minilibx-linux/mlx.h"

typedef struct s_map
{
    char    **tab;
    char    **tmp;
    char        unknown;
    int     player;
    char        dir;
}           t_map;

typedef struct s_image
{
    //Variables pour les murs
    void    *NO;
    void    *SO;
    void    *WE;
    void    *EA;
    char    *path_NO;
    char    *path_SO;
    char    *path_WE;
    char    *path_EA;

    //Variables pour le sol et le plafon
    int     F; //Sol
    int     Fr; //rouge
    int     Fg; //vert
    int     Fb; //bleu

    int     C; //Plafon
    int     Cr; //rouge
    int     Cg; //vert
    int     Cb; //bleu

    int     x;
    int     y;
}       t_image;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_map   *map;
    t_image img;
}           t_data;

void    error(char *str);

#endif

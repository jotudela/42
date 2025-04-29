/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:42:55 by jojo              #+#    #+#             */
/*   Updated: 2025/04/29 11:05:10 by jotudela         ###   ########.fr       */
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

t_data  *init_data(void);
void    free_tab(char **tab);
void    free_data(t_data **data);
void    ft_is_good_format(char *file);
void    error(char *str);
int    ft_init_data(t_data **data, char *file);
void    free_data(t_data **data);
void    free_tab(char **tab);
int ft_get_rgb(t_data **data, char *line);
void  ft_get_texture_path(t_data **data, char *line);
int    ft_reallocTab(t_data **data, char *line);
int     ft_coppyTab(t_data **data);

#endif

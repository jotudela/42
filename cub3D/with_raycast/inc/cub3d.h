/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:42:55 by jojo              #+#    #+#             */
/*   Updated: 2025/05/06 18:45:38 by jotudela         ###   ########.fr       */
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
# include "../Utils/get_next_line/get_next_line_bonus.h"
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_minimap
{
    void    *m_img_ptr;
    char    *m_pixels;
    int     m_bits_per_pixel;
    int     m_line_length;
    int     m_endian;
}           t_minimap;

typedef struct s_map
{
    char    **tab;
    char    **tmp;
    int     player;
    char        dir;
    int     map_x;
    int     map_y;
    int     len_x;
    int     len_y;
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

    //Taile de la fenetre
    int     img_x;
    int     img_y;

    //Image finale
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;

    //Pour generer les textures
    int     x;
    int     y;
}       t_image;

typedef struct s_player
{
    float x;
    float y;
    float dirX;
    float dirY;
    float planeX;
    float planeY;
}           t_player;

typedef struct  s_keys
{
    int a;
    int d;
    int w;
    int s;
    int left;
    int right;
}           t_keys;

typedef struct s_data
{
    void        *mlx;
    void        *win;
    int         is_map;
    int         is_paused;
    int         is_game;
    t_map       *map;
    t_minimap   minimap;
    t_player    player;
    t_image     img;
    t_keys      keys;
}           t_data;

/* Functions for parsing and check */
t_data  *init_data(void);
int     ft_init_data(t_data **data, char *file);
int     ft_get_rgb(t_data **data, char *line);
void    ft_get_texture_path(t_data **data, char *line);
int     ft_reallocTab(t_data **data, char *line);
void    normalize_map(t_data **data);
int     ft_lenTab(char **tab);
int     ft_coppyTab(t_data **data);

/* Functions for check all data */
void    ft_is_good_format(char *file);
int     ft_checkPlayer(t_data **data);
int     ft_checkChar(t_data **data);
int     check_all_map(t_data *data);

/* Functions for game */
void    cub3d(t_data **data);
int     key_press(int keycode, t_data *data);
int     key_release(int keycode, t_data *data);
void    create_minimap(t_data **data);
void    draw_player(t_data *mlx, t_player *player, int tile_size);
int     close_cross(t_data *data);
void    raycasting(t_data *data);
void    create_img_background(t_data **data);
void    draw_walls(t_data *data, int x, int drawStart, int drawEnd, int color);

/* Functions utils */
void    error(char *str);
void    free_tab(char **tab);
void    free_data(t_data **data);

#endif
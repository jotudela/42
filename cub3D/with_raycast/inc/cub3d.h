/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:42:55 by jojo              #+#    #+#             */
/*   Updated: 2025/05/01 13:53:54 by jotudela         ###   ########.fr       */
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

/* Configuration de la fenetre */
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define FOV 60

/* Couleurs définies pour faciliter le débogage */
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define BLACK 0x000000

/* Codes des touches */
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_M 109  /* Pour activer/désactiver la minimap */

/* Paramètres du joueur */
# define MOVE_SPEED 0.05
# define ROTATION_SPEED 0.03

/* Structure pour les points et vecteurs */
typedef struct s_vec
{
    double  x;
    double  y;
}           t_vec;

typedef struct s_map
{
    char    **tab;
    char    **tmp;
    int     player;
    char        dir;
    int     map_x;
    int     map_y;
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
    int     *texture_data[4]; /* Data de texture en pixels */
    int     texture_width;
    int     texture_height;

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

    //Image à dessiner
    void    *img_ptr;
    char    *addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;

    //Pour generer les textures
    int     x;
    int     y;
}       t_image;

/* Structure pour le joueur */
typedef struct s_player
{
    t_vec   pos;       /* Position x,y */
    t_vec   dir;       /* Direction (vecteur unitaire) */
    t_vec   plane;     /* Plan de caméra (perpendiculaire à dir) */
    double  move_speed;
    double  rot_speed;
}           t_player;

/* Structure pour le raycasting */
typedef struct s_ray
{
    t_vec   dir;       /* Direction du rayon */
    t_vec   delta_dist; /* Distance entre intersections */
    t_vec   side_dist; /* Distance au prochain côté */
    t_vec   map;       /* Position actuelle dans la grille */
    t_vec   step;      /* Direction des pas (1 ou -1) */
    int     side;      /* Mur touché (0 = vertical, 1 = horizontal) */
    double  perp_wall_dist; /* Distance perpendiculaire au mur */
    double  wall_x;    /* Coordonnée exacte de la collision */
    int     line_height; /* Hauteur de la ligne à dessiner */
    int     draw_start; /* Début de la ligne */
    int     draw_end;   /* Fin de la ligne */
    int     tex_x;     /* Coordonnée x de la texture */
    int     tex_num;   /* Numéro de la texture à utiliser */
}           t_ray;

typedef struct s_data
{
    void        *mlx;
    void        *win;
    t_map       *map;
    t_image     img;
    t_player    player;
    t_ray       ray;
    int         minimap;
}           t_data;

/* Functions for parsing and check */
t_data  *init_data(void);
int     ft_init_data(t_data **data, char *file);
int     ft_get_rgb(t_data **data, char *line);
void    ft_get_texture_path(t_data **data, char *line);
int     ft_reallocTab(t_data **data, char *line);
int     ft_coppyTab(t_data **data);

/* Functions for check all data */
void    ft_is_good_format(char *file);
int     ft_checkPlayer(t_data **data);
int     ft_checkChar(t_data **data);
int     flood_fill(t_data **data, int x, int y);

/* Functions for game */
void    cub3d(t_data **data);
int     key_press(int keycode, t_data *data);
int     close_cross(t_data *data);
void    create_img(t_data **data);
void    init_player(t_data **data);
void    load_textures(t_data **data);

/* Functions for raycasting */
void    raycast(t_data *data);
void    calc_ray_dir(t_data *data, int x);
void    perform_dda(t_data *data);
void    calc_wall_height(t_data *data);
void    draw_vertical_line(t_data *data, int x);
void    draw_textured_line(t_data *data, int x);
double  get_wall_x(t_data *data);
int     get_tex_x(t_data *data, double wall_x);

/* Functions for movement and controls */
void    move_forward(t_data *data);
void    move_backward(t_data *data);
void    strafe_left(t_data *data);
void    strafe_right(t_data *data);
void    rotate_left(t_data *data);
void    rotate_right(t_data *data);

/* Functions for minimap (optional) */
void    draw_minimap(t_data *data);
void    draw_player_on_minimap(t_data *data);

/* Functions for rendering */
void    clear_screen(t_data *data);
void    put_pixel(t_data *data, int x, int y, int color);
int     game_loop(void *param);

/* Math helper functions */
double  normalize_angle(double angle);
int     rgb_to_int(int r, int g, int b);

/* Functions utils */
void    error(char *str);
void    free_tab(char **tab);
void    free_data(t_data **data);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:42:55 by jojo              #+#    #+#             */
/*   Updated: 2025/06/25 13:05:25 by jotudela         ###   ########.fr       */
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
	void	*m_img_ptr;
	char	*m_pixels;
	int		m_bits_per_pixel;
	int		m_line_length;
	int		m_endian;
	int		color;
}			t_minimap;

typedef struct s_map
{
	char	**tab;
	char	**tmp;
	int		player;
	char	dir;
	int		map_x;
	int		map_y;
	int		len_x;
	int		len_y;
}			t_map;

typedef struct s_tex_info
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_tex_info;

typedef struct s_image
{
	t_tex_info	no;
	t_tex_info	so;
	t_tex_info	we;
	t_tex_info	ea;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	int			f;
	int			fr;
	int			fg;
	int			fb;
	int			c;
	int			cr;
	int			cg;
	int			cb;
	int			img_x;
	int			img_y;
	int			color;
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			x;
	int			y;
}			t_image;

typedef struct s_raycast
{
	float			camerax;
	float			raydirx;
	float			raydiry;
	float			sidedistx;
	float			sidedisty;
	float			deltadistx;
	float			deltadisty;
	float			perpwalldist;
	float			wallx;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				texx;
	int				texy;
	int				texnum;
	int				d;
	unsigned int	color;
}			t_raycast;

typedef struct s_player
{
	float	x;
	float	y;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
	float	move;
	float	rot;
}			t_player;

typedef struct s_keys
{
	int	a;
	int	d;
	int	w;
	int	s;
	int	left;
	int	right;
}			t_keys;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_minimap	minimap;
	t_player	player;
	t_image		img;
	t_keys		keys;
}			t_data;

/* Functions for parsing and check */
t_data	*init_data(void);
int		ft_init_data(t_data **data, char *file);
int		ft_get_rgb(t_data **data, char *line);
void	ft_get_texture_path(t_data **data, char *line);
int		ft_realloctab(t_data **data, char *line);
void	normalize_map(t_data **data);
int		ft_lentab(char **tab);
int		ft_coppytab(t_data **data);

/* Functions for check all data */
void	ft_is_good_format(char *file);
int		ft_checkplayer(t_data **data);
int		ft_checkchar(t_data **data);
int		check_all_map(t_data *data);

/* Functions for game */
void	cub3d(t_data **data);
int		game_loop(t_data *data);
int		key_press(int keycode, t_data *data);
int		key_release(int keycode, t_data *data);
int		generate_textures(t_data *data);
int		close_cross(t_data *data);
void	raycasting(t_data *data);
void	which_tex(t_data *data, t_raycast *r, t_tex_info **tex);
void	create_img_background(t_data **data);
int		is_walkable(t_data *data, float x, float y);
void	draw_walls(t_data *data, int x, t_tex_info *tex, t_raycast r);
void	handle_map_input(t_data *data);
void	handle_movement_loop(t_data *data);
void	update_camera(t_data *data);

/* Functions utils */
void	error(char *str);
void	ft_cleangnl(int fd);
void	free_tab(char **tab);
void	free_data(t_data **data);
void	ft_draw_img(t_data **data);

#endif

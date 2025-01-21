/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:41:44 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/21 15:37:59 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Utils/libft/libft.h"
# include "../Utils/ft_printf/ft_printf.h"
# include "../Utils/get_next_line/get_next_line_bonus.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>

/* Defines */

# define WALL "textures/wall.xpm"
# define TREE "textures/tree.xpm"
# define FLOOR "textures/floor.xpm"
# define LINK "textures/link.xpm"
# define TRIFORCE "textures/triforce.xpm"
# define EXIT1 "textures/exit1.xpm"
# define EXIT2 "textures/exit2.xpm"

/* Structures */

typedef struct s_map
{
	char			*line;
	char			*tmp;
	char			target;
	int				len_line;
	int				empty;
	int				wall;
	int				item;
	int				exit;
	int				player;
	struct s_map	*next;
	struct s_map	*prev;
}			t_map;

typedef struct s_control
{
	int	x;
	int	y;
	int	item;
	int	exit;
	int	player;
	int	type_error;
}			t_control;

typedef struct s_image
{
	void	*wall;
	void	*tree;
	char	*floor;
	int		*link;
	int		*triforce;
	int		*exit1;
	int		*exit2;
	int		x;
	int		y;
}			t_image;

typedef struct s_player
{
	int	x;
	int	y;
	int	xe;
	int	ye;
	int	ni;
}			t_player;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				len_lst;
	int				actions;
	t_map			**map;
	t_control		**su;
	t_image			img;
	t_player		player;
}			t_data;

/* Prototypes */

/* List functions */
t_map		*ft_lstnew(char *new_line, int len);
void		ft_mapclear(t_map **lst);
void		ft_lstadd_front(t_map **lst, t_map *new);
void		ft_lstadd_back(t_map **lst, t_map *new);
t_map		*ft_lstlast(t_map *lst);
t_map		*ft_init(char *file);
void		ft_suclear(t_control **su);
t_control	*new_su(void);

/* Utils */
void		ft_closefds(void);

/* Update */
void		ft_update(t_map *map);

/* Check map functions */
int			ft_control(t_map *map, t_control *su);
int			is_rectangle(t_map *map, t_control *su);
int			ft_lstlen(t_map *map);
int			is_cep(t_map *map, t_control *su);
int			char_is_invalid(t_map *map, t_control *su);
int			good_outline(t_map *map, t_control *su);
int			good_len_line(t_map *map, t_control *su);
int			path_valid(t_map *map, t_control *su);

/* Game */
void		game(t_map **map, t_control **su);
void		so_long(t_map **map, t_control **su);
int			generate_textures(t_data *data);
int			key_press(int keycode, t_data *data);
int			close_cross(t_data *data);
int			close_win(t_data *data);
int			close_win2(t_data *data);
void		print_image(t_data *data, void *img, int x, int y);
void		print_map(t_data *data, t_map *map);
void		position(t_data *data, t_map *map);
void		find_e(t_map *map, t_data *data);
void		is_finish(t_data *data, t_map *map);
void		print_floor(t_data *data, t_map *map);

#endif

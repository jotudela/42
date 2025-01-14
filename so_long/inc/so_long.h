/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:41:44 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/14 14:47:48 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Utils/libft/libft.h"
# include "../Utils/ft_printf/ft_printf.h"
# include "../Utils/get_next_line/get_next_line_bonus.h"

/* Toutes les structures */

typedef struct s_map
{
	char	*line;
	int		len_line;
	int		empty;
	int		wall;
	int		item;
	int		exit;
	int		player;
	struct s_map	*next;
}			t_map;

typedef struct s_control
{
	int		x;// Horizontal
	int		y;// Vertical
	int		item;
	int		exit;
	int		player;
	int		type_error;
}			t_control;

/* Tout les prototypes */

/* Prototypes for list */

t_map	*ft_lstnew(char *new_line, int len);
void	ft_mapclear(t_map **lst);
void	ft_lstadd_front(t_map **lst, t_map *new);
void	ft_lstadd_back(t_map **lst, t_map *new);
t_map	*ft_lstlast(t_map *lst);
t_map   *ft_init(char *file);
t_control   *new_su(void);
int		ft_control(t_map *map, t_control *su);
void	ft_suclear(t_control **su);

/* Prototypes for Utils */

void    ft_closefds(void);

/* Prototypes for Update */

void	ft_update(t_map *map);

#endif

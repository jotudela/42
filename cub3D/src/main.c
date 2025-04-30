/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:40:10 by jojo              #+#    #+#             */
/*   Updated: 2025/04/30 10:15:19 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*void    print_data(t_data **data)
{
    int i = 0;
    printf("path_NO: %s", (*data)->img.path_NO ? (*data)->img.path_NO : "NULL");
    printf("path_SO: %s", (*data)->img.path_SO ? (*data)->img.path_SO : "NULL");
    printf("path_WE: %s", (*data)->img.path_WE ? (*data)->img.path_WE : "NULL");
    printf("path_EA: %s", (*data)->img.path_EA ? (*data)->img.path_EA : "NULL");
    printf("C: %d\n", (*data)->img.C);
    printf("F: %d\n\n", (*data)->img.F);
    if ((*data)->map->tab)
    {
        while ((*data)->map->tab[i])
            printf("%s", (*data)->map->tab[i++]);
        printf("\n\n\n");
    }
    if ((*data)->map->tmp)
    {
        i = 0;
        while ((*data)->map->tmp[i])
            printf("%s", (*data)->map->tmp[i++]);
        printf("\n");
    }
    printf("%c\n", (*data)->map->dir);
    printf("%i\n", (*data)->map->map_x);
    printf("%i\n", (*data)->map->map_y);
}*/

int main(int ac, char **av)
{
    t_data  *data;

    if (ac != 2)
        (error("error: exec: arguments format './cub3D maps/.cub'\n"), exit(1));
    ft_is_good_format(av[1]);
    data = init_data();
    ft_init_data(&data, av[1]);
    //print_data(&data);
    free_data(&data);
}

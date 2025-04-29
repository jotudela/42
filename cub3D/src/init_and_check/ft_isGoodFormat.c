/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isGoodFormat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:53:48 by jotudela          #+#    #+#             */
/*   Updated: 2025/04/29 10:54:17 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cube3d.h"

void    ft_is_good_format(char *file)
{
    int len;

    len = ft_strlen(file) - 1;
    if (file[len] != 'b'
        || file[len - 1] != 'u'
        || file[len - 2] != 'c'
        || file[len - 3] != '.')
        (error("error: file: format is not on .cub !\n"), exit(1));
    return ;
}

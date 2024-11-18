/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:51:19 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/18 10:10:31 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_putunsigned_fd(unsigned int num, int fd)
{
    char buffer[20];
    int i;

    if (num == 0) {
        write(fd, "0", 1);
        return;
    }
    i = 0;
    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }
    while (i-- > 0)
        write(fd, &buffer[i], 1);
}
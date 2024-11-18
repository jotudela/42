/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:49:47 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/18 10:10:35 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_putptr(void *ptr, int fd)
{
    const char *hex_digits;
    unsigned long num;
    char buffer[20];
    int i;

    num = (unsigned long)ptr;
    if (num == 0) {
        ft_putstr_fd("0x0", fd);
        return;
    }
    hex_digits = "0123456789abcdef";
    i = 0;
    while (num > 0) {
        buffer[i++] = hex_digits[num % 16];
        num /= 16;
    }
    ft_putstr_fd("0x", fd);
    while (i-- > 0)
        write(fd, &buffer[i], 1);
}
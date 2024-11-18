/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_xX.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:52:25 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/18 10:10:28 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_putnbr_hex(int num, int fd, char c)
{
    const char *hex_digits;
    char buffer[20];
    int i;
    unsigned int unsigned_num;

    unsigned_num = num;
    if (unsigned_num == 0)
    {
        write(fd, "0", 1);
        return;
    }
    if (c == 'x')
        hex_digits = "0123456789abcdef";
    else if (c == 'X')
        hex_digits = "0123456789ABCDEF"; 
    i = 0;
    while (unsigned_num > 0)
    {
        buffer[i++] = hex_digits[unsigned_num % 16];
        unsigned_num /= 16;
    }
    while (i-- > 0)
        write(fd, &buffer[i], 1);
}
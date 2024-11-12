/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:49:29 by jojo              #+#    #+#             */
/*   Updated: 2024/11/04 14:51:57 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void print_value(List li)
{
    if (li->convert == 'c')
        ft_putchar_fd(li->value, 1);
    else if (li->convert == 's')
        ft_putstr_fd(li->value, 1);
    else if (li->convert == 'd' || li->convert == 'u')
    {
        ft_putnbr_fd(li->value / 10, 1);
        ft_putchar_fd('.', 1);
        ft_putnbr_fd(li->value % 10, 1);
    }
    else if (li->convert == 'i')
        ft_putnbr_fd(li->value, 1);
    else if (li->convert == 'p' || li->convert == 'x')
        ft_putnbr_fd(ft_atoi_base(li->value, "0123456789abcdef"), 1);
    else if (li->convert == 'X')
        ft_putstr_fd(ft_atoi_base(li->value, "0123456789ABCDEF"), 1);
    else if (li->convert == '%')
        ft_putnbr_fd(li->value, 1);
    else
    {
        ft_putendl_fd("Type de convertion non reconnue !", 2);
        exit(1);
    }
}

static void print_all(const char *format, List li)
{
    int i;

    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            print_value(li);
            li = li->next;
        }
        ft_putchar_fd(format[i], 1);
        i++;
    }
}

int     ft_printf(const char *format, ...)
{
    va_list args;
    ListElement *li;
    va_start(args, count_list_len(format));
    li = ultimate_parse(format, args);
    va_end(args);
    print_all(format, li);
    clear_list(li);
}

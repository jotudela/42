/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:49:29 by jojo              #+#    #+#             */
/*   Updated: 2024/11/18 10:10:21 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int    ft_print_format(char c, va_list args)
{
    if (c == 'c')
        ft_putchar_fd(va_arg(args, int), 1);
    else if (c == 's')
        ft_putstr_fd(va_arg(args, char *), 1);
    else if (c == 'i' || c == 'd')
        ft_putint_fd(va_arg(args, int), 1);
    else if (c == 'p')
        ft_putptr(va_arg(args, void *), 1);
    else if (c == 'u')
        ft_putunsigned_fd(va_arg(args, unsigned int), 1);
    else if (c == 'x' || c == 'X')
        ft_putnbr_hex(va_arg(args, int), 1, c);
    else if (c == '%')
        ft_putchar_fd(c, 1);
    return (0);
}

int good_format(char c)
{
    if (c == 'c')
        return (1);
    else if (c == 's')
        return (1);
    else if (c == 'p')
        return (1);
    else if (c == 'i')
        return (1);
    else if (c == 'd')
        return (1);
    else if (c == 'u')
        return (1);
    else if (c == 'x')
        return (1);
    else if (c == 'X')
        return (1);
    return (0);
}

int ft_verif_format(const char *format)
{
    int i;

    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == '%')
                i++;
            else if (good_format(format[i + 1]) == 0)
                return (1);
        }
        i++;
    }
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;

    if (ft_verif_format(format) == 1)
    {
        ft_putstr_fd("ERREUR: arret du programme.", 2);
        return (1); 
    }
    va_start(args, format);
    i = 0;
    while (format[i])
    {
        if (format[i] == '%')
        {
            ft_print_format(format[i + 1], args);
            i++;
        }
        else
            ft_putchar_fd(format[i], 1);
        i++;
    }
    va_end(args);
    return (0);
}

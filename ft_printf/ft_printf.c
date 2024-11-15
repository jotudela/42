/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:49:29 by jojo              #+#    #+#             */
/*   Updated: 2024/11/15 16:40:44 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *str, int fd)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar_fd(str[i], fd);
        i++;
    }
}
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
    while (num > 0) {
        buffer[i++] = hex_digits[num % 16];
        num /= 16;
    }
    ft_putstr_fd("0x", fd);
    while (i-- > 0)
        write(fd, &buffer[i], 1);
}

void    ft_putint_fd(int n, int fd)
{
    if (n == MIN)
    {
        ft_putstr_fd("-2147483648", fd);
        return ;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
        ft_putint_fd(n, fd);
    }
    else if (n > 9)
    {
        ft_putint_fd(n / 10, fd);
        ft_putint_fd(n % 10, fd);
    }
    else
        ft_putchar_fd(n + '0', fd);
}

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

void    ft_putnbr_hex(int num, int fd, char c)
{
    const char *hex_digits;
    char buffer[20];
    int i;
    unsigned int unsigned_num;

    unsigned_num = num;
    if (unsigned_num == 0) {
        write(fd, "0", 1);
        return;
    }
    if (c == 'x')
        hex_digits = "0123456789abcdef";
    else if (c == 'X')
        hex_digits = "0123456789ABCDEF"; 
    i = 0;
    while (unsigned_num > 0) {
        buffer[i++] = hex_digits[unsigned_num % 16];
        unsigned_num /= 16;
    }
    while (i-- > 0)
        write(fd, &buffer[i], 1);
}

int    ft_print_format1(char c, va_list args)
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
            ft_print_format1(format[i + 1], args);
            i++;
        }
        else
            ft_putchar_fd(format[i], 1);
        i++;
    }
    va_end(args);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_from_libft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:28:22 by jojo              #+#    #+#             */
/*   Updated: 2024/10/30 14:53:21 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *str, int fd)
{
    int     i;

    i = 0;
    while (str[i])
    {
        ft_putchar_fd(str[i], fd);
    }
}

void    ft_putendl_fd(char *str, int fd)
{
    ft_putstr_fd(str, fd);
    ft_putchar_fd('\n', fd);
}

void    ft_putnbr_fd(int n, int fd)
{
    if (n == MIN)
    {
        ft_putchar_fd('-', fd);
        ft_putchar_fd('2', fd);
        ft_putnbr_fd(147483648, fd);
    }
    else if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
        ft_putnbr_fd(n, fd);
    }
    else if (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
        ft_putchar_fd(n + '0', fd);
}

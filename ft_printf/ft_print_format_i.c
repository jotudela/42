/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:48:38 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/18 10:10:38 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
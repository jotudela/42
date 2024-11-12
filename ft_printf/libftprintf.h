/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:52:53 by jojo              #+#    #+#             */
/*   Updated: 2024/10/30 16:51:26 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define MIN -2147483648
# define MAX 2147483647

# include "list.h"
# include <unistd.h>

int     ft_printf(const char *format, ...);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *str, int fd);
void    ft_putendl_fd(char *str, int fd);
void    ft_putnbr_fd(int n, int fd);
int ft_strlen(char *str);
int	ft_atoi_base(char *str, char *base);
List    ultimate_parse(const char *format, *args);

#endif
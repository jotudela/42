/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:52:53 by jojo              #+#    #+#             */
/*   Updated: 2024/11/18 10:11:15 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define MIN -2147483648
# define MAX 2147483647

# include <stdarg.h>
# include <unistd.h>

int     ft_printf(const char *format, ...);
void    ft_putchar_fd(char c, int fd);
void    ft_putint_fd(int n, int fd);
void    ft_putptr(void *ptr, int fd);
void    ft_putstr_fd(char *str, int fd);
void    ft_putunsigned_fd(unsigned int num, int fd);
void    ft_putnbr_hex(int num, int fd, char c);

#endif
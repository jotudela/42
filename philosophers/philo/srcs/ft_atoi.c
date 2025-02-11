/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:59:40 by mmeuric           #+#    #+#             */
/*   Updated: 2025/02/11 10:14:43 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	putstr_fd(int fd, char *str)
{
	while (*str)
		write(fd, str++, 1);
}

#include <unistd.h>

void ft_putnbr_long(long n)
{
    char buffer[20];
    int i = 0;
    
    if (n < 0)
	{
        write(1, "-", 1);
        n = -n;
    }
    if (n == 0)
        buffer[i++] = '0';
	else
	{
        while (n > 0)
		{
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }
    while (i > 0)
	{
        i--;
        write(1, &buffer[i], 1);
    }
}


long	ft_atoi(const char *str)
{
	long	nb;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb = nb + (str[i] - '0');
		i++;
		if (nb > INT_MAX)
			break ;
	}
	return (nb * sign);
}

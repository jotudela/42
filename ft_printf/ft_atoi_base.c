/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:16:48 by jojo              #+#    #+#             */
/*   Updated: 2024/10/30 16:39:20 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_atoi(char *str, int len)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * len + str[i];
		i++;
	}
	return (res * neg);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	len;
    
	len = ft_strlen(base);
	nbr = ft_atoi(str, len);
	return (nbr);
}
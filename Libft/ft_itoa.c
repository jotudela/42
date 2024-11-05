/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/10/17 13:12:25 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	size_t	i;
	char	c;
	size_t	size;

	i = 0;
	size = ft_strlen(str);
	while (i < size / 2)
	{
		c = str[size - 1 - i];
		str[size - 1 - i] = str[i];
		str[i] = c;
		i++;
	}
	str[size] = '\0';
	return (str);
}

static size_t	total_len(int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_nnot_good(int n)
{
	char	*str;

	str = NULL;
	if (n == 0)
	{
		str = ft_calloc(2, sizeof(char));
		if (!str)
			return (NULL);
		str = "0\0";
	}
	else if (n == -2147483648)
	{
		str = ft_calloc(12, sizeof(char));
		if (!str)
			return (NULL);
		str = "-2147483648\0";
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		neg;
	size_t	i;
	char	*str;

	if (n == 0 || n == -2147483648)
		return (ft_nnot_good(n));
	neg = n;
	if (n < 0)
		n *= -1;
	len = total_len(n);
	str = ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (neg < 0)
		str[i] = '-';
	return (ft_strrev(str));
}

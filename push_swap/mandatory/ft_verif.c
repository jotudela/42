/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:00:05 by jojo              #+#    #+#             */
/*   Updated: 2025/01/13 12:21:10 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	msg_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	ft_outlen(char *str)
{
	int			itmp;
	const char	*atmp;

	itmp = ft_atoi(str);
	atmp = ft_itoa(itmp);
	if (!atmp)
		return (1);
	if (ft_strncmp((const char *)str, atmp, ft_strlen(str)) != 0)
		return (free((char *)atmp), 1);
	free((char *)atmp);
	return (0);
}

int	ft_double(int ac, char **av, int mod)
{
	int	i;
	int	j;
	int	tmp1;
	int	tmp2;

	i = mod;
	while (i < ac)
	{
		tmp1 = ft_atoi(av[i]);
		j = i + 1;
		while (j < ac)
		{
			tmp2 = ft_atoi(av[j]);
			if (tmp1 == tmp2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_verif(int ac, char **av, int mod)
{
	int	i;
	int	j;

	i = mod;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_outlen(av[i]) == 1)
				return (1);
			else if (av[i][j] == '-' && (av[i][j + 1] < '0'
					|| av[i][j + 1] > '9'))
				return (1);
			else if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	if (ft_double(ac, av, mod) == 1)
		return (1);
	return (0);
}

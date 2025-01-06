/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:00:05 by jojo              #+#    #+#             */
/*   Updated: 2024/12/17 15:38:02 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	msg_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int		ft_outlen(char *str)
{
	int		itmp;
	char	*atmp;

	itmp = ft_atoi(str);
	atmp = ft_itoa(itmp);
	if (!atmp)
		return (1);
	if (ft_strncmp((const char *)str, (const char *)atmp, ft_strlen((const char *)str)) != 0)
		return (free(atmp), 1);
	free(atmp);
	return (0);
}

int ft_double(int ac, char **av)
{
    int i;
    int j;
    int tmp1;
    int tmp2;

    i = 1;
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

void	ft_verif(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_outlen(av[i]) == 1)
				msg_error("Error\n");
			else if (av[i][j] == '-' && (av[i][j + 1] < '0' || av[i][j + 1] > '9'))
				msg_error("Error\n");
			else if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-')
				msg_error("Error\n");
			j++;
		}
		i++;
	}
	if (ft_double(ac, av) == 1)
		msg_error("Error\n");
}
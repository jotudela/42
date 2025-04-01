/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:31:59 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 02:08:33 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"

int	consist_of(char *line, char c)
{
	return (count(line, c) == ft_strlen(line));
}

size_t	count(const char *s, int c)
{
	size_t	res;

	res = 0;
	while (*s)
		res += *s++ == c;
	return (res);
}

static void	print_args(int argc, char **args, int i)
{
	while (i < argc - 1)
	{
		ft_putstr_fd(args[i], 1);
		if (ft_strlen(args[i]))
			ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putstr_fd(args[i++], 1);
}

int	is_option(char *str)
{
	if (!str)
		return (0);
	if (*str && *str == '-' && ft_strlen(str + 1) && consist_of(str + 1, 'n'))
		return (1);
	return (0);
}

int	echo(int argc, char **args)
{
	int		new_line;
	int		i;
	char	*opt;

	i = 0;
	new_line = 1;
	while (i <= argc - 1)
	{
		opt = args[i];
		if (is_option(opt))
		{
			new_line = 0;
			i++;
		}
		else
			break ;
	}
	print_args(argc, args, i);
	if (new_line)
		ft_putstr_fd("\n", 1);
	return (0);
}

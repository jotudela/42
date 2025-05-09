/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocTab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 09:30:27 by jotudela          #+#    #+#             */
/*   Updated: 2025/05/09 09:11:48 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_lentab(char **tab)
{
	int	i;

	if (!tab || !*tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static int	ft_allocfirst(t_data **data, char *line)
{
	char	**new_tab;

	new_tab = ft_calloc(sizeof(char *), 2);
	if (!new_tab)
		return (-1);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	new_tab[0] = ft_strdup(line);
	new_tab[1] = NULL;
	(*data)->map->tab = new_tab;
	return (0);
}

static char	*no_newline(char *line)
{
	char	*new_line;
	char	*tmp;
	int		len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		tmp = ft_strdup(line);
		if (!tmp)
			return (NULL);
		tmp[len - 1] = '\0';
		new_line = ft_strdup(tmp);
		free(tmp);
	}
	else
		new_line = ft_strdup(line);
	if (!new_line)
		return (NULL);
	return (new_line);
}

int	ft_realloctab(t_data **data, char *line)
{
	char	**new_tab;
	int		len_tab;
	int		i;

	if (!line)
		return (0);
	if (!(*data)->map->tab)
		return (ft_allocfirst(data, line));
	len_tab = ft_lentab((*data)->map->tab) + 2;
	new_tab = ft_calloc(sizeof(char *), len_tab);
	if (!new_tab)
		return (-1);
	i = 0;
	while ((*data)->map->tab[i])
	{
		new_tab[i] = no_newline((*data)->map->tab[i]);
		if (!new_tab[i])
			return (free_tab(new_tab), -1);
		i++;
	}
	new_tab[i++] = no_newline(line);
	new_tab[i] = NULL;
	free_tab((*data)->map->tab);
	(*data)->map->tab = new_tab;
	return (0);
}

int	ft_coppytab(t_data **data)
{
	int	len_tab;
	int	i;

	if (!(*data)->map->tab)
		return (-1);
	len_tab = ft_lentab((*data)->map->tab) + 1;
	(*data)->map->tmp = ft_calloc(sizeof(char *), len_tab);
	if (!(*data)->map->tmp)
		return (-1);
	i = 0;
	while ((*data)->map->tab[i])
	{
		(*data)->map->tmp[i] = ft_strdup((*data)->map->tab[i]);
		if (!(*data)->map->tmp[i])
			return (-1);
		i++;
	}
	(*data)->map->tmp[i] = NULL;
	return (0);
}

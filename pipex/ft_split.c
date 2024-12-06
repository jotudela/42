/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:09:08 by jojo              #+#    #+#             */
/*   Updated: 2024/12/06 11:12:23 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static void	sub_check(char const *s, char c, size_t *i, size_t *start)
{
	while (s[*i] == c)
		(*i)++;
	if (s[*i] != c && s[*i])
	{
		*start = *i;
		while (s[*i] != c && s[*i])
			(*i)++;
	}
}

static int	ft_init(char **buffer, char const *s, char c, size_t len_s)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		sub_check(s, c, &i, &start);
		if (j < len_s)
		{
			buffer[j] = ft_calloc(sizeof(char), (i - start + 1));
			if (!buffer[j])
				return (0);
			ft_strncpy(buffer[j], &s[start], i - start);
			j++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (1);
}

static size_t	ft_tab_len(char const *str, char c)
{
	size_t	result;
	int		i;

	result = 0;
	i = 0;
	if (c == '\0')
		return (1);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			result++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	len_s;
	size_t	i;

	if (!s)
		return (NULL);
	len_s = ft_tab_len(s, c);
	tab = (char **)ft_calloc(sizeof(char *), (len_s + 1));
	if (!tab)
		return (NULL);
	if (ft_init(tab, s, c, len_s) == 0)
	{
		i = 0;
		while (i < len_s)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		tab = NULL;
	}
	return (tab);
}

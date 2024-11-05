/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/11/05 14:25:14 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	tab_len(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
        }
	return (len);
}

static size_t	len_str(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*ft_strncpy(char const *s, char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] && i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	free_tab(char **tab, size_t boite)
{
	while (boite > 0)
		free(tab[--boite]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	boite;
	size_t	len;
	size_t	i;

	tab = malloc(sizeof(char *) * tab_len(s, c));
	if (!tab)
		return (NULL);
	boite = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = len_str(s + i, c);
		tab[boite] = malloc(len + 1);
		if (!tab[boite])
		{
			free_tab(tab, boite);
			return (NULL);
		}
		ft_strncpy((char *)s + i, tab[boite++], len);
		i += len;
	}
	tab[boite] = NULL;
	return (tab);
}

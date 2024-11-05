/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtudela <joantudela66.2.4@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/11/05 15:17:36 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	total_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;
	int		found;

	i = 0;
	count = 0;
	while (s1[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			count++;
		i++;
	}
	return (count + 1);
}

static void	ft_strcpy(char *str, char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		found;

	i = 0;
	k = 0;
	while (s1[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (!found)
			str[k++] = s1[i];
		i++;
	}
	str[k] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = total_len(s1, set);
	str = ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1, set);
	return (str);
}

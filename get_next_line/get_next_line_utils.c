/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:50:34 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/14 15:48:52 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*li;

	li = malloc(sizeof(*li));
	if (!li)
		return (NULL);
	li->content = ft_strdup(content);
	li->next = NULL;
	return (li);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*li;
    t_list  *tmp;

	if (!lst || !new)
		return ;
    tmp = &lst;
    while (tmp != NULL)
        tmp = tmp->next;
    li = (*tmp);
	if (!li)
		*lst = new;
	else
		li->next = new;
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
    size_t  i;

    len = 0;
	while (s1[len])
        len++;
	ptr = ft_calloc(len, sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
    while (i < len - 1)
    {
        ((char *)ptr)[i] = ((char *)s1)[i];
        i++;
    }
	ptr[len - 1] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_calloc(1, sizeof(char)));
	if (len > size - start)
		len = size - start;
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	size = 0;
    s += start;
    while (size < len)
    {
        ptr[size] = (char *)s[size];
        size++;
    }
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str1;

	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen(s));
	str1 = (unsigned char *)s;
	while (str1[i])
	{
		if (str1[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

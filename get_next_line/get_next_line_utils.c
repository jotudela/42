/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:50:34 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/14 13:38:25 by jotudela         ###   ########.fr       */
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

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*li;

	if (!lst || !new)
		return ;
	li = ft_lstlast(*lst);
	if (!li)
		*lst = new;
	else
		li->next = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
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

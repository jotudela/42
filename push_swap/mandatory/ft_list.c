/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:19:54 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/13 11:27:19 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*ft_lstnew(int new_value)
{
	t_list	*li;

	li = malloc(sizeof(*li));
	if (!li)
		return (NULL);
	li->value = new_value;
	li->index = 0;
	li->pos = -1;
	li->target_pos = -1;
	li->cost_a = -1;
	li->cost_b = -1;
	li->next = NULL;
	return (li);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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

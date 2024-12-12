/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:40:58 by jojo              #+#    #+#             */
/*   Updated: 2024/12/12 10:33:43 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_lstclear(t_args **lst)
{
	t_args	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_cleartab((*lst)->args);
		free((*lst)->path);
		free(*lst);
		*lst = tmp;
	}
}

t_args	*ft_lstnew(char *command, char **envp, int mod, char *file)
{
	t_args	*li;

	li = malloc(sizeof(*li));
	if (!li)
		return (NULL);
	li->args = ft_split(command, ' ');
	li->path = ft_find_cmd(li->args[0]);
	li->env = envp;
	li->mod = mod;
	li->file1 = NULL;
	li->file2 = NULL;
	if (li->mod == 1)
		li->file1 = file;
	else if (li->mod == 2)
		li->file2 = file;
	li->next = NULL;
	return (li);
}

t_args	*ft_lstlast(t_args *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_args **lst, t_args *new)
{
	t_args	*li;

	if (!lst || !new)
		msg_error("lst or new, problem");
	li = ft_lstlast(*lst);
	if (!li)
		*lst = new;
	else
		li->next = new;
}

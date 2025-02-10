/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:21:40 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/10 17:15:10 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    ft_cleartab(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
    args = NULL;
}

void	ft_lstclear(t_commands **lst)
{
	t_commands	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
        free((*lst)->path);
		free(*lst);
		*lst = tmp;
	}
}

t_commands	*ft_lstnew(char *command, char **envp, int mod, char *file)
{
	t_commands	*li;

	li = ft_calloc(sizeof(*li), 1);
	if (!li)
		return (NULL);
	li->args = command;
	li->path = ft_find_cmd(command);
	li->env = envp;
	li->mod = mod;
	li->file1 = NULL;
	if (li->mod == 1)
		li->file1 = file;
	else if (li->mod == 2)
	li->next = NULL;
	return (li);
}

t_commands	*ft_lstlast(t_commands *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_commands **lst, t_commands *new)
{
	t_commands	*li;

	if (!lst || !new)
		msg_error("lst or new, problem");
	li = ft_lstlast(*lst);
	if (!li)
		*lst = new;
	else
		li->next = new;
}
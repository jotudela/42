/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:52 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 03:05:09 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <global_utils.h>
#include <ft_lsts.h>
#include <stdlib.h>

void	del_from_env(t_env **env, char *key)
{
	t_env	*node;

	if (!env || !*env)
		return ;
	node = search_in_env(*env, key);
	if (!node)
		return ;
	if (node == *env)
		*env = (*env)->next;
	else if (!node->next)
		node->prev->next = NULL;
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	ft_lstdelone(node, free);
}

int	unset(int argc, char **args, t_env **env)
{
	char	*ptr;
	int		i;

	if (!args || !env)
		return (1);
	i = 0;
	while (i < argc)
	{
		ptr = args[i++];
		if (validate_arg(ptr))
			continue ;
		del_from_env(env, ptr);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:30:03 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/27 11:08:09 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cd_utils.h"
#include <stdio.h>
/*
int	cd(char *arg, t_env *env)
{
	t_env	*node;

	if (!arg)
	{
		node = search_in_env(env, "HOME");
		if (!node)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
		else
			return (change_directory(node->value));
	}
	else
		return (change_directory(arg));
}

int	cd(char *arg, t_env *env)
{
	t_env	*node;
	int		ret;

	if (!arg)
	{
		node = search_in_env(env, "HOME");
		if (!node)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
		else
			return (change_directory(node->value));
	}
	else if (!ft_strcmp(arg, "-"))
	{
		node = search_in_env(env, "OLDPWD");
		if (!node)
		{
			printf("cd: OLDPWD not set\n");
			return (1);
		}
		ret = change_directory(node->value);
		// Affichage du nouveau chemin comme le fait bash lors de "cd -"
		if (ret == 0)
			printf("%s\n", node->value);
		return (ret);
	}
	else
		return (change_directory(arg));
}
*/
int	cd(char *arg, t_env *env)
{
	t_env	*node;
	int		ret;

	if (!arg)
	{
		node = search_in_env(env, "HOME");
		if (!node)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
		else
			return (change_directory(node->value)); // Ajout de env
	}
	else if (!ft_strcmp(arg, "-"))
	{
		node = search_in_env(env, "OLDPWD");
		if (!node)
		{
			printf("cd: OLDPWD not set\n");
			return (1);
		}
		ret = change_directory(node->value); // Ajout de env
		// Affichage du nouveau chemin comme le fait bash lors de "cd -"
		if (ret == 0)
			printf("%s\n", node->value);
		return (ret);
	}
	else
		return (change_directory(arg)); // Ajout de env
}

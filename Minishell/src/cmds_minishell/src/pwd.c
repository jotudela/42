/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:38:19 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 02:44:27 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <global_utils.h>
#include <stdio.h>

char	*pwd_cmd(char *str)
{
	static char	*pwd;
	t_env		*env;
	t_env		*pwd_node;
	char		*new_pwd;

	if (!str)
		return (pwd);
	env = get_envp(NULL);
	pwd_node = search_in_env(env, "PWD");
	if (pwd_node)
		set_env_value(ft_strdup("OLDPWD"), ft_strdup(pwd_node->value), 1);
	else
		set_env_value(ft_strdup("OLDPWD"), ft_strdup(""), 1);
	free(pwd);
	pwd = trim_path(str);
	new_pwd = ft_strdup(pwd);
	set_env_value(ft_strdup("PWD"), new_pwd, 1);
	return (pwd);
}

void	shift_slice(char **slices)
{
	if (!slices && !*slices)
		return ;
	free(slices[0]);
	slices[0] = NULL;
	while (slices[1])
	{
		slices[0] = slices[1];
		slices++;
	}
	slices[0] = slices[1];
}

char	*trim_path(char *pwd)
{
	char	*result;
	char	**slices;
	char	**slice_ptr;
	size_t	i;

	if (!pwd)
		return (NULL);
	slices = ft_split(pwd, '/');
	slice_ptr = slices;
	i = 0;
	while (slice_ptr[i])
	{
		if (!ft_strcmp(slice_ptr[i], "."))
		{
			shift_slice(&slice_ptr[i]);
			slice_ptr = slices;
			continue ;
		}
		i++;
	}
	result = contruct_path(slices);
	return (free_list(slices), result);
}

int	pwd(void)
{
	printf("%s\n", pwd_cmd(NULL));
	return (0);
}

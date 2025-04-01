/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:35:25 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 02:57:53 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	export(int argc, char **argv, t_env **env)
{
	char	*ptr;
	char	*key;
	int		res;

	if (!env)
		return (1);
	if (!argc)
		return (print_exports(*env));
	res = 0;
	while (*argv)
	{
		ptr = *argv++;
		if ((!ft_strchr(ptr, '=') && search_in_env(*env, ptr))
			|| validate_arg(ptr))
		{
			res = 1;
			continue ;
		}
		if (handle_concate_case(ptr))
			continue ;
		key = get_key(ptr);
		set_env_value(key, get_value(ptr), !!ft_strchr(ptr, '='));
	}
	return (res);
}

int	handle_concate_case(char *line)
{
	if (!line || !is_concate(line))
		return (0);
	concate_env(get_key(line), get_value(line));
	return (1);
}

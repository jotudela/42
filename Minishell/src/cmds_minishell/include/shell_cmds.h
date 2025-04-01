/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cmds.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:24:55 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 01:44:56 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_CMDS_H
# define SHELL_CMDS_H
# include <libft.h>

int	echo(int argc, char **args);
int	pwd(void);
int	cd(char *arg, t_env *env);
#endif

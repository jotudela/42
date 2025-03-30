/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrlz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:07:08 by jojo              #+#    #+#             */
/*   Updated: 2025/03/30 12:35:10 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

void	handler_sigtstp(int sig)
{
	(void)sig;
}

/*
** Affiche le répertoire de travail actuel sous une forme 
** colorée dans le prompt.
*/
void	prompt_pwd(void)
{
	ft_putstr_fd("" BLUE, 1);
	ft_putstr_fd(pwd_cmd(NULL), 1);
	ft_putendl_fd("" NOCOL "", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrlz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:32:37 by jotudela          #+#    #+#             */
/*   Updated: 2025/03/25 14:55:26 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

void    handler_SIGTSTP(int sig)
{
    (void)sig;
}

void    sigquit_handler(int sig)
{
    (void)sig;
}

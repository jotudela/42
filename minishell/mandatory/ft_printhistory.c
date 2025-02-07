/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhistory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:34:57 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/07 12:55:28 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void print_line(const char *line)
{
    write(STDOUT_FILENO, "\r", 1);  // Réafficher l'invite de commande
    write(STDOUT_FILENO, Hello, ft_strlen(Hello));
    write(STDOUT_FILENO, line, ft_strlen(line));
}

void ft_rl_on_new_line()
{
    write(STDOUT_FILENO, "\n", 1);
}

// Remplace la ligne en cours par une nouvelle ligne
void ft_rl_replace_line(const char *new_line)
{
    write(STDOUT_FILENO, "\r", 1);
    write(STDOUT_FILENO, new_line, strlen(new_line));
}

// Réaffiche l'invite de commande
void ft_rl_redisplay()
{
    write(STDOUT_FILENO, "\r", 1);
    write(STDOUT_FILENO, Hello, ft_strlen(Hello));
}

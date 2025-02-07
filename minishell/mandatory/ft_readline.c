/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:31:17 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/07 13:18:35 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

static void handle_arrow_up(t_history *history, char *buffer, int *pos)
{
    if (!history->current)
        history->current = history->tail;
    else if (history->current->prev)
        history->current = history->current->prev;

    if (history->current)
        ft_strlcpy(buffer, history->current->line, sizeof(buffer));
    else
        buffer[0] = '\0';

    *pos = ft_strlen(buffer);
    print_line(buffer);
}

static void handle_arrow_down(t_history *history, char *buffer, int *pos)
{
    if (history->current && history->current->next)
        history->current = history->current->next;
    else
        history->current = NULL;

    if (history->current)
        ft_strlcpy(buffer, history->current->line, sizeof(buffer));
    else
        buffer[0] = '\0';

    *pos = ft_strlen(buffer);
    print_line(buffer);
}

static void handle_arrow_keys(t_history *history, char *buffer, int *pos, char direction)
{
    if (direction == 'A') // Flèche haut
        handle_arrow_up(history, buffer, pos);
    else if (direction == 'B') // Flèche bas
        handle_arrow_down(history, buffer, pos);
}

static void handle_character_input(char *buffer, int *pos, char c)
{
    if (*pos < 1023)
    {
        buffer[(*pos)++] = c;
        buffer[*pos] = '\0';
        write(STDOUT_FILENO, &c, 1);
    }
}

char *ft_readline(t_history *history)
{
    char buffer[1024];  // Buffer pour stocker la ligne
    int pos = 0;        // Position actuelle dans le buffer
    char c;             // Caractère lu depuis l'entrée
    char seq[2];        // Séquence pour les touches fléchées

    while (1)
    {
        if (read(STDIN_FILENO, &c, 1) != 1)
            continue;

        // Si l'utilisateur appuie sur "Entrée" (nouvelle ligne)
        if (c == '\n')
        {
            buffer[pos] = '\0';   // Terminer la ligne
            write(STDOUT_FILENO, "\n", 1);

            // Si la ligne est vide, on redonne le prompt sans quitter
            if (pos == 0)
            {
                ft_rl_redisplay();  // Redispay le prompt
                continue;
            }

            // Si la ligne n'est pas vide, l'ajouter à l'historique
            ft_add_history(history, buffer);

            // Si l'utilisateur a tapé "exit", quitter le programme
            if (ft_strncmp(buffer, "exit", 4) == 0)
            {
                return (NULL);  // Quitter le programme
            }

            // Retourner la ligne entrée par l'utilisateur
            return (ft_strdup(buffer));
        }

        // Gestion des séquences d'échappement (flèches)
        if (c == 27 && read(STDIN_FILENO, &seq[0], 1) == 1 && read(STDIN_FILENO, &seq[1], 1) == 1 && seq[0] == '[')
        {
            handle_arrow_keys(history, buffer, &pos, seq[1]);
            continue;
        }

        // Gestion des caractères classiques (ajouter le caractère dans le buffer)
        if (c != 127 && c != 4)  // Ignorer "Backspace" et "Ctrl-D" dans ce bloc
        {
            handle_character_input(buffer, &pos, c);
        }

        // Gestion de la touche Backspace (supprimer un caractère avant le curseur)
        if (c == 127)  // "Backspace"
        {
            if (pos > 0)  // S'il y a des caractères à supprimer
            {
                pos--;  // Décaler la position
                buffer[pos] = '\0';  // Supprimer le dernier caractère
                print_line(buffer);  // Réafficher la ligne modifiée
            }
        }

        // Gestion de la touche Delete (Ctrl-D)
        if (c == 4)  // Ctrl-D
        {
            write(STDOUT_FILENO, "\n", 1);  // Ajouter une nouvelle ligne avant de quitter
            return (NULL);  // Retourner NULL pour signaler un EOF
        }
    }
}



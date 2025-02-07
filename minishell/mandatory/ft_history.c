/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:22:11 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/07 10:28:15 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void init_history(t_history *history)
{
    history->head = history->tail = history->current = NULL;
}

void ft_add_history(t_history *history, const char *line)
{
    t_historique *new_node;
    
    new_node = malloc(sizeof(t_historique));
    if (!new_node)
        return;
    new_node->line = ft_strdup(line);
    new_node->next = NULL;
    new_node->prev = history->tail;
    if (history->tail) {
        history->tail->next = new_node;
    } else {
        history->head = new_node;
    }
    history->tail = new_node;
    history->current = NULL;
}

void ft_rl_clear_history(t_history *history)
{
    t_historique *current;
    
    current = history->head;
    while (current) {
        t_historique *next = current->next;
        free(current->line);
        free(current);
        current = next;
    }
    history->head = history->tail = history->current = NULL;
}

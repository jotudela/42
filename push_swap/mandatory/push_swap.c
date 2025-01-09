/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:23:48 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/09 13:27:04 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Fonction pour obtenir la taille de la pile
int stack_size(t_list *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

// Fonction pour trouver l'index trié des éléments
void assign_index(t_list *stack) {
    t_list *ptr1;
    t_list *ptr2;
    int index;

    ptr1 = stack;
    while (ptr1) {
        index = 0;
        ptr2 = stack;
        while (ptr2) {
            if (ptr1->value > ptr2->value)
                index++;
            ptr2 = ptr2->next;
        }
        ptr1->index = index; // On remplace la valeur par l'index trié
        ptr1 = ptr1->next;
    }
}

// Fonction principale pour le tri Radix
void radix_sort(t_list **a, t_list **b) {
    int size = stack_size(*a);
    int max_bits = 0;
    int i, j;

    // Trouver le nombre de bits nécessaires
    while ((size - 1) >> max_bits != 0)
        max_bits++;

    // Effectuer le tri pour chaque bit
    for (i = 0; i < max_bits; i++) {
        j = 0;
        while (j < size) {
            if (((*a)->index >> i) & 1)
                ra(a); // Bit 1 -> rotation dans A
            else
                pb(a, b); // Bit 0 -> push vers B
            j++;
        }
        while (*b)
            pa(a, b); // Remettre tous les éléments dans A
        if (is_ok(*a) == 0)
            break ;
    }
}

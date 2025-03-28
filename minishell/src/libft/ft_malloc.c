/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:34:09 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/27 13:26:46 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
void	*ft_malloc(unsigned long size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		write(2, "shell42: MALLOC FAILED\n", 22);
		exit(88);
	}
	return (ptr);
}
*/
#include <stdlib.h>
#include <unistd.h>

t_alloc *g_allocs = NULL; // Liste globale des allocations

void *ft_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr)
        return NULL;

    // Ajouter l'allocation à la liste chaînée
    t_alloc *new_alloc = malloc(sizeof(t_alloc));
    if (!new_alloc)
        return NULL;
    new_alloc->ptr = ptr;
    new_alloc->next = g_allocs;
    g_allocs = new_alloc;

    return ptr;
}
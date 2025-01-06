/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:36:01 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/06 14:25:57 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int lst_len(t_list **a)
{
    int i;

    i = 0;
    while (a)
    {
        i++;
        a = a->next;
    }
    return (i);
}

void    sa(int e1, int e2, t_list **a)
{
    int  tmp;
    if (!a || lst_len(&a) == 1)
        return ;
    tmp = e1;
    e1 = e2;
    e2 = tmp;
}
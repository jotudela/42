/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:10:29 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/06 14:26:02 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int lst_len(t_list **b)
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

void    sb(int e1, int e2, t_list **b)
{
    int  tmp;
    if (!a || lst_len(&b) == 1)
        return ;
    tmp = e1;
    e1 = e2;
    e2 = tmp;
}
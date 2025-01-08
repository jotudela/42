/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:13:07 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/08 17:28:54 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    printlst(t_list *li)
{
    while (li)
    {
        ft_printf("%i\n", li->value);
        li = li->next;
    }
}

int main(int ac, char **av)
{
    t_list *a = ft_init(ac, av);
    printlst(a);
    ft_lstclear(&a);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:13:07 by jotudela          #+#    #+#             */
/*   Updated: 2025/01/09 13:01:43 by jotudela         ###   ########.fr       */
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
    t_list *b = NULL;
    
    if (is_ok(a) == 1)
    {  
        assign_index(a);
        radix_sort(&a, &b);
    }
    ft_lstclear(&a);
    ft_lstclear(&b);
    return (0);
}

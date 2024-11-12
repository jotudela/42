/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:50:26 by jojo              #+#    #+#             */
/*   Updated: 2024/10/30 16:45:22 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int  is_convert(char c)
{
    if (c == 'c')
        return (1);
    else if (c == 's')
        return (1);
    else if (c == 'p')
        return (1);
    else if (c == 'd')
        return (1);
    else if (c == 'i')
        return (1);
    else if (c == 'u')
        return (1);
    else if (c == 'x')
        return (1);
    else if (c == 'X')
        return (1);
    else if (c == '%')
        return (1);
    return (0);
}
static int  count_list_len(const char *format)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (format[i])
    {
        if (format[i] == '%')
            len += 1;
        i++;
    }
    return (len);
}
List    ultimate_parse(const char *format, *args)
{
    int len;
    int i;
    int k;
    ListElement *li;

    len = count_list_len(format);
    i = 0;
    k = 0;
    li = NULL;
    while (i < len)
    {
        while (is_convert(format[k]) == 0)
            k++;
        li = push_back_list(li, args, format[k]);
        i++;
        k++;
    }
    return (li);
}

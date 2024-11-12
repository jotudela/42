/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:49:47 by jojo              #+#    #+#             */
/*   Updated: 2024/10/30 16:07:24 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	push_value(void *value, *args, char c)
{
	if (c == 'c')
		value = va_arg(args, char);
	else if (c == 's')
        value = va_arg(args, char *);
    else if (c == 'p')
        value = va_arg(args, char *);
    else if (c == 'd')
        value = va_arg(args, int);
    else if (c == 'i')
        value = va_arg(args, int);
    else if (c == 'u')
        value = va_arg(args, unsigned int);
    else if (c == 'x')
        value = va_arg(args, char *);
    else if (c == 'X')
        value = va_arg(args, char *);
    else if (c == '%')
        value = va_arg(args, char);
	else
	{
		ft_putendl_fd("Type de convertion non reconnue !", 2);
		exit(1);
	}
}

List push_back_list(List li, *args, char c)
{
	ListElement *element;
	ListElement *tmp;
	
	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		ft_putendl_fd("Erreur sur l'allocation dynamique.", 2);
		exit(1);
	}
	push_value(element->value, args, c);
	element->convert = c;
	element->next = NULL;
	if(li == NULL)
		return element;
	tmp = li;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = element;
	return li;
}

List pop_front_list(List li)
{
	ListElement *element;

	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		ft_putendl_fd("Erreur sur l'allocation dynamique.", 2);
		exit(1);
	}
	if (li == NULL)
		return new_list();
	element = li->next;
	free(li);
	li = NULL;
	return element;
}

List clear_list(List li)
{
	if (li == NULL)
		return new_list();
	while (li != NULL)
		li = pop_front_list(li);
	return 0;
}

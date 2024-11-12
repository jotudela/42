/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:49:56 by jojo              #+#    #+#             */
/*   Updated: 2024/11/04 14:49:14 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST__H_
# define LIST__H_

# include <stdlib.h>
# include <stdarg.h>

typedef struct ListElement
{
	void *value;
	char convert;
	struct ListElement *next;
}ListElement, *List;

void push_value(void *value, *args, char c);
List push_back_list(List li, *args, char c);
List pop_front_list(List li);
List clear_list(List li);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:57:40 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/15 16:44:15 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("My version : %s%i%s\n", "Hello tout le monde. Je suis Joan et j'ai ", 19, "ans.");
	printf("Real version : %s%i%s\n", "Hello tout le monde. Je suis Joan et j'ai ", 19, "ans.");
}

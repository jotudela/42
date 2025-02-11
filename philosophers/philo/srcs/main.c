/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:57:44 by mmeuric           #+#    #+#             */
/*   Updated: 2025/02/11 14:49:19 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_init	init;

	if (ft_verif(argc, argv) == 1)
		return (1);
	if (argc == 6)
		if (ft_atoi(argv[5]) == 0)
			return (write(1, "🎉 All philosophers ate 0 times 🎉\n", 39));
	ft_init(&init, argv);
	close_simulation(&init);
	ft_clean(&init);
	return (0);
}

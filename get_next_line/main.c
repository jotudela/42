/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:21:02 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/14 14:54:54 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(void)
{
 	int fd = open("lorem_ipsum", O_RDONLY);
	char	*line;
	int	i = 3;
	while(i > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
		i--;
	}
	close (fd);
}

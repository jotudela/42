/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_str.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:28:19 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/31 21:49:57 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTRUCT_STR_H
# define CONSTRUCT_STR_H

# include "libft.h"

typedef struct s_stringbuilder
{
	size_t	capacity;
	size_t	used_len;
	char	*str;
}	t_strbuilder;

void			sb_reallocate(t_strbuilder *sb, size_t len);
t_strbuilder	*stringbuilder(void);
t_strbuilder	*sb_append(t_strbuilder *sb, char *str);
t_strbuilder	*sb_append_free(t_strbuilder *sb, char *str);
t_strbuilder	*sb_append_int(t_strbuilder *sb, int nb);
void			sb_free(t_strbuilder *sb);

#endif

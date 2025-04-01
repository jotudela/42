/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:27:22 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 00:33:45 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H
# include <syntax_tree.h>
# include <variable_resolver.h>
# include <shared_defs.h>
# include <signals.h>
# include <construct_str.h>

char	*handle_heredoc(char *delim, bool expand_env);
char	*ft_mktmp(void);
int		patch_heredoc(t_ast_cmd *tree);
void	patch_token(t_ast_redir *tree);
bool	is_expandable(t_token *tok);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:26:35 by mmeuric           #+#    #+#             */
/*   Updated: 2025/04/01 01:26:47 by mmeuric          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYNTAX_ANALYZER_H
# define SYNTAX_ANALYZER_H

# include "syntax_tree.h"
# include "tokenizer.h"
# include "error.h"
# include "heredoc.h"

bool	syntax_analyzer(t_token *tokens, t_ast_cmd **tree);

#endif // SYNTAX_ANALYZER_H

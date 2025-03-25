/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:52:42 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/25 14:58:35 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

void	sigint_handler(int sig)
{
	(void)sig;
	if (waitpid(-1, NULL, WNOHANG) == -1)
	{
		printf("\n");
		prompt_pwd();
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		set_exit_status(1);
		g_signal_status = 69;
	}
}

void	heredoc_sigint_handler(int sig)
{
	(void)sig;
	set_exit_status(1);
	g_signal_status = 420;
	close(0);
}

void	handle_default_sig_handlers(int action)
{
	if (action == SET)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, sigquit_handler);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	return ;
}

void	reset_default_sig_handlers(void)
{
	handle_default_sig_handlers(RESET);
}

void	install_default_sig_handlers(void)
{
	handle_default_sig_handlers(SET);
}

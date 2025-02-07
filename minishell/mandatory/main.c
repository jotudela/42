/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:16:42 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/07 13:01:52 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void	handle_signals(int signum)
{
	(void)signum;
	if (waitpid(-1, NULL, WNOHANG) == -1)
	{
		write(STDOUT_FILENO, "^C", 2);
		ft_rl_on_new_line();
		ft_rl_replace_line("");
		ft_rl_redisplay();
	}
}

void	sigquit_handler(int signum)
{
	(void)signum;
}

void setup_signals(void)
{
    signal(2, handle_signals);
	signal(3, handle_signals);
}

void    handle_imput(t_history *h, char *line, char **envp)
{
    char    cwd[PATH_MAX];
    (void)envp;
    if (ft_strncmp(line, "exit\n", ft_strlen(line)) == 0) //si l'utilisateur rentre "exit"
    {
        free(line);
        printf("bye 👋 !\n");
        exit(0);
    }
    if (*line)
        ft_add_history(h, line);
    if (ft_strncmp(line, "pwd\n\0", ft_strlen(line)) == 0)
        printf("%s\n", getcwd(cwd, sizeof(cwd)));
}

int main(int ac, char **av, char **envp)
{
    t_history h;

    (void)av;
    init_history(&h);
    enableRawMode();
    if (ac != 1)
        return (write(2, "Error\nFormat to execute : ./minishell", 38));
    setup_signals();
    while (1)
    {
        write(1, Hello, ft_strlen(Hello));
        ft_readline(&h);
        if (h.head == NULL || h.head->line == NULL)
        {
            printf("bye 👋 !\n");
            ft_rl_clear_history(&h); // Nettoyage de l'historique avant de quitter
            exit(0);
        }
        if (h.head->line == (void*)0) //si l'utilisateur ne met rien
            continue ;
        handle_imput(&h, h.head->line, envp);
    }
    ft_rl_clear_history(&h);
    return (0);
}

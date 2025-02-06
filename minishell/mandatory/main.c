/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:16:42 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/06 16:52:21 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void handle_signal(int sig)
{
    if (sig == SIGINT) //crtl-C
    {
        printf("\n");          // Nouvelle ligne
        rl_on_new_line();      // Reset readline
        rl_replace_line("", 0); // Efface ligne actuelle
        rl_redisplay();        // Réaffiche prompt
    }
    else if (sig == SIGQUIT) /*ctrl-\*/
    {
        rl_on_new_line();      // Reset readline
        rl_replace_line("", 0); // Efface ligne actuelle
        rl_redisplay();
    }
}

void setup_signals(void)
{
    struct sigaction sa;
    
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    
    sigaction(SIGINT, &sa, NULL);
    sigaction(SIGQUIT, &sa, NULL);
}

void    handle_imput(char *line, char **envp)
{
    char    cwd[PATH_MAX];
    (void)envp;
    if (ft_strncmp(line, "exit\n\0", ft_strlen(line)) == 0) //si l'utilisateur rentre "exit"
    {
        free(line);
        printf("bye 👋 !\n");
        exit(0);
    }
    if (*line)
        add_history(line);
    if (ft_strncmp(line, "pwd\n\0", ft_strlen(line)) == 0)
        printf("%s\n", getcwd(cwd, sizeof(cwd)));
}

int main(int ac, char **av, char **envp)
{
    char    *line;

    (void)av;
    if (ac != 1)
        return (write(2, "Error\nFormat to execute : ./minishell", 38));
    setup_signals();
    while (1)
    {
        line = readline(Hello);
        if (!line) //ctrl-D
        {
            printf("bye 👋 !\n");
            exit(0);
        }
        if (*line == '\0') //si l'utilisateur ne met rien
        {
            free(line);
            continue ;
        }
        handle_imput(line, envp);
        free(line);
    }
    free(line);
    return (0);
}

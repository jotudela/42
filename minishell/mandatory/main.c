/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:16:42 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/07 17:40:10 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void    handle_imput(t_history *h, char *line, char **envp)
{
    (void)envp;
    if (ft_strncmp(line, "exit\n", ft_strlen(line)) == 0) //si l'utilisateur rentre "exit"
    {
        ft_rl_clear_history(h);
        printf("bye 👋 !\n");
        exit(0);
    }
    if (*line)
        ft_add_history(h, line);
    /*if (ft_strncmp(line, "pwd\n\0", ft_strlen(line)) == 0)
        printf("%s\n", getcwd(cwd, sizeof(cwd)));*/
    //passer a la fonction qui va tout recuperer et en meme temps executer ce que je passe
}

int main(int ac, char **av, char **envp)
{
    t_history h;

    (void)av;
    if (ac != 1)
        return (write(2, "Error\nFormat to execute : ./minishell", 38));
    init_history(&h);
    enableRawMode();
    setup_signals();
    while (1)
    {
        write(1, Hello, ft_strlen(Hello));
        ft_readline(&h);
        if (!h.head || !h.head->line)
        {
            printf("bye 👋 !\n");
            ft_rl_clear_history(&h); // Nettoyage de l'historique avant de quitter
            exit(0);
        }
        if (!*(h.head->line)) //si l'utilisateur ne met rien
            continue ;
        handle_imput(&h, h.tail->line, envp);
    }
    ft_rl_clear_history(&h);
    return (0);
}

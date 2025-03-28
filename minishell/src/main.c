/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:55:32 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/28 13:31:15 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>
#include <exit.h>
#include <globals.h>
#include <lexer.h>
#include <parser.h>
#include <signals.h>
#include <termios.h>
#include "libft.h"


int		g_signal_status;

/*
** Affiche le répertoire de travail actuel sous une forme 
** colorée dans le prompt.
*/
void	prompt_pwd(void)
{
	ft_putstr_fd("" BLUE, 1);
	ft_putstr_fd(pwd_cmd(NULL), 1);
	ft_putendl_fd("" NOCOL "", 1);
}

/*
** Modifie ou récupère les attributs du terminal en fonction de 
** l'action spécifiée :
** - ATTR_GET : Récupère les attributs du terminal (stdin, stdout, stderr).
** - ATTR_SET : Applique les attributs modifiés au terminal.
** - ATTR_CHG : Désactive l'affichage des caractères de contrôle 
** (comme Ctrl+C).
*/
void	tty_attr(struct termios *attrs, int action)
{
	if (action == ATTR_GET)
	{
		tcgetattr(STDIN_FILENO, &attrs[0]);
		tcgetattr(STDOUT_FILENO, &attrs[1]);
		tcgetattr(STDERR_FILENO, &attrs[2]);
	}
	else if (action == ATTR_SET)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &attrs[0]);
		tcsetattr(STDOUT_FILENO, TCSANOW, &attrs[1]);
		tcsetattr(STDERR_FILENO, TCSANOW, &attrs[2]);
	}
	else if (action == ATTR_CHG)
	{
		attrs[0].c_lflag &= ~ECHOCTL;
		attrs[1].c_lflag &= ~ECHOCTL;
		attrs[2].c_lflag &= ~ECHOCTL;
		tty_attr(attrs, ATTR_SET);
	}
}

/*
** Initialise l'environnement du shell :
** - Charge les variables d'environnement.
** - Définit le répertoire de travail initial.
** - Configure la gestion des signaux.
**
	- Modifie les attributs du terminal pour désactiver
	 l'affichage des caractères de contrôle.
*/
void	initialize_shell(char **envp, struct termios *attrs, ...)
{
	char	*tmp;

	create_env(envp);
	tmp = getcwd(NULL, 0);
	rl_catch_signals = false;
	pwd_cmd(tmp);
	free(tmp);
	install_default_sig_handlers();
	tty_attr(attrs, ATTR_GET);
	tty_attr(attrs, ATTR_CHG);
}

/*
** Traite une ligne de commande :
** - Vérifie si la commande est vide (cas où l'utilisateur a pressé Ctrl+D).
** - Effectue l'analyse lexicale (tokenization) de la commande.
** - Analyse syntaxiquement la commande et l'exécute si elle est valide.
** - Enregistre la commande dans l'historique si elle est non vide.
*/
bool	parse_and_execute(char *command_line)
{
	t_token		*tokens;
	t_ast_cmd	*ast;

	if (!command_line)
	{
		ft_putendl_fd("exit", 1);
		return (free(command_line), true);
	}
	// Si la commande est "exit", on sort du shell
    if (ft_strcmp(command_line, "exit") == 0)
    {
        return (free(command_line), true);  // Retourne true pour quitter
    }
	lexer(command_line, &tokens);
	if (parser(tokens, &ast))
		executor(ast, false);
	else
	{
		dup2(2, 0);
		g_signal_status = 0;
	}
	if (*command_line)
	{
		add_history(command_line);
	}
	return (free_ast(ast), free(command_line), false);
}

void ft_free_all(void) {
    t_alloc *tmp;
    while (g_allocs) {
        tmp = g_allocs;
        g_allocs = g_allocs->next;
        free(tmp->ptr);
        free(tmp); // Libération de la structure elle-même
    }
}

/*
** Fonction principale du minishell :
** - Initialise l'environnement et configure le terminal.
** - Boucle infinie pour afficher le prompt et lire les commandes.
** - Exécute chaque commande et gère les signaux.
**
	- Termine le programme si l'utilisateur entre "exit" 
	ou envoie un signal d'arrêt.
*/
int	main(int _, char **__, char **envp)
{
	char			*command_line;
	struct termios	attrs[3];

	initialize_shell(envp, attrs, _, __);
	if (signal(SIGTSTP, handler_SIGTSTP) == SIG_ERR)
	{
        perror("Erreur lors de l'attachement du gestionnaire de signal");
        exit(1);
    }
	while (true)
	{
		if (g_signal_status != 88)
			prompt_pwd();
		command_line = readline("💻 ");
		if (parse_and_execute(command_line))
			break ;
		g_signal_status = 0;
		tty_attr(attrs, ATTR_SET);
	}
	ft_free_all();
	exit(get_exit_status());
}

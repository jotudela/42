/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:55:32 by mmeuric           #+#    #+#             */
/*   Updated: 2025/03/30 16:31:41 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>
#include <exit.h>
#include <globals.h>
#include <lexer.h>
#include <parser.h>
#include <signals.h>
#include <termios.h>

int		g_signal_status;

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
	int		value;

	create_env(envp);
	tmp = getcwd(NULL, 0);
	rl_catch_signals = false;
	pwd_cmd(tmp);
	free(tmp);
	tmp = get_env_value(ft_strdup(" SHLVL"));
	value = ft_atoi(tmp);
	value += 1;
	if (value > 1000)
		value = 1;
	free(tmp);
	tmp = ft_itoa(value);
	set_env_value(ft_strdup("SHLVL"), ft_strdup(tmp), 1);
	free(tmp);
	install_default_sig_handlers();
	tty_attr(attrs, ATTR_GET);
	tty_attr(attrs, ATTR_CHG);
}

void	free_env(void)
{
	t_env	*env;
	t_env	*prev;

	env = *get_envp_internal(NULL);
	while (env)
	{
		free(env->key);
		free(env->value);
		prev = env;
		env = env->next;
		free(prev);
	}
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
		return (ft_putendl_fd("exit", 1),
			free_env(), free(command_line), true);
	if (ft_strcmp(command_line, "exit") == 0)
	{
		(free(command_line), free_env(), free(pwd_cmd(NULL)));
		exit(get_exit_status());
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
	if (signal(SIGTSTP, handler_sigtstp) == SIG_ERR)
	{
		perror("Erreur lors de l'attachement du gestionnaire de signal");
		exit(get_exit_status());
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
	free(pwd_cmd(NULL));
	exit(get_exit_status());
}

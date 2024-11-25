#include "pipex.h"

int	main(int ac, char **av)
{
	if (ac != 5)
		perror("Erreur nombre d'argument.");
	else if (access(av[1], F_OK) == -1)
	{
		printf("Le fichier %s n'existe pas.\n", av[1]);
		exit(EXIT_FAILURE);
	}
	else if (access(av[4], F_OK) == -1)
	{
		pid_t	pid = fork();
		if (pid == -1){
			perror("Erreur fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			char *args[] = {"touch", av[4], NULL};
			char *env[] = {NULL};

			if (execve("/usr/bin/touch", args, env) == -1){
				perror("Erreur execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
				printf("Fichier %s créé avec succès\n", av[4]);
            		}
			else
				printf("Échec de création du fichier\n");
		}
	}
    	else
		printf("Le fichier %s existe déjà\n", av[4]);
	return (0);
}

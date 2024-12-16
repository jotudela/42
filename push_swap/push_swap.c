#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	msg_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	ft_ilen(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 10)
		msg_error("Error\n");
	return (i);
}

void	ft_verif(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '0' && av[i][j] <= '9')
				av[i][j] += ft_ilen(av[i] + j);
			else if (av[i][j] == '-' && (av[i][j + 1] >= '0' && av[i][j + 1] <= '9'))
				av[i][j] += ft_ilen(av[i] + j + 1);
			else if (av[i][j] == '-' && (av[i][j + 1] < '0' || av[i][j + 1] > '9'))
				msg_error("Error\n");
			else if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-')
				msg_error("Error\n");
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
		exit(EXIT_FAILURE);
	ft_verif(av);
}

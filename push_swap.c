#include "push_swap.h"

int	ft_isdigit(int i)
{
	if ((i >= 48) && (i <= 57))
		return (1);
	else
		return (0);
}

int	parsing(char *av)
{
	int	nb;

	while (*av)
	{
		while (ft_isdigit(*av))	
		{
			nb = *av;
			av++;	
		}
		if (*av == 32)
			av++;
		else
		{
			printf("Error");
			exit(1);
		}
		av++;
	}
	return(1);
}

int main(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
		parsing(av[i++]);
		// push dans la liste creer back int
}
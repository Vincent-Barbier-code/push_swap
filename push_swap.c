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
	while (*av)
	{
		if (ft_isdigit(*av))
			av++;
		else
		{
			printf("Error");
			exit(1);
		}
	}
	

}

int main(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
		parsing(av[i++]);

}